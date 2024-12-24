#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <map>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_EVENTS 10

std::map<int, int> client_map;  // 客户端配对表

int main() {
    int server_socket, epoll_fd;
    struct sockaddr_in server_addr;

    // 创建服务器套接字
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        std::cerr << "创建服务器套接字失败。" << std::endl;
        return -1;
    }

    // 设置地址复用，避免端口占用问题
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // 初始化服务器地址
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // 绑定地址到服务器套接字
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "绑定失败。" << std::endl;
        return -1;
    }

    // 监听端口
    if (listen(server_socket, 10) < 0) {
        std::cerr << "监听失败。" << std::endl;
        return -1;
    }

    // 创建 epoll 实例
    epoll_fd = epoll_create(128);//代表epoll模型的 fd
    if (epoll_fd == -1) {
        std::cerr << "创建 epoll 实例失败。" << std::endl;
        return -1;
    }

    // 将服务器套接字添加到 epoll 实例中，监听连接请求
    struct epoll_event event;
    event.events = EPOLLIN;
    event.data.fd = server_socket;
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, server_socket, &event);

    std::cout << "服务器启动，等待客户端连接..." << std::endl;

    struct epoll_event events[MAX_EVENTS];

    while (true) {
        int event_count = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);  // 无限等待事件

        for (int i = 0; i < event_count; ++i) {
            if (events[i].data.fd == server_socket) {
                // 处理新的客户端连接
                struct sockaddr_in client_addr;
                socklen_t client_len = sizeof(client_addr);
                int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_len);

                if (client_socket == -1) {
                    std::cerr << "接受客户端连接失败。" << std::endl;
                    continue;
                }

                std::cout << "新客户端连接: " << inet_ntoa(client_addr.sin_addr) << std::endl;

                // 将新客户端套接字添加到 epoll 监听中
                event.events = EPOLLIN;
                event.data.fd = client_socket;
                epoll_ctl(epoll_fd, EPOLL_CTL_ADD, client_socket, &event);

                // 客户端配对处理
                if (client_map.empty()) {
                    client_map[client_socket] = -1;  // 第一个客户端，暂时没有配对
                } else {
                    for (auto& pair : client_map) {
                        if (pair.second == -1) {
                            client_map[client_socket] = pair.first;  // 配对
                            client_map[pair.first] = client_socket;
                            break;
                        }
                    }
                }
            } else {
                // 处理客户端的消息收发
                int client_socket = events[i].data.fd;
                char buffer[BUFFER_SIZE];
                memset(buffer, 0, sizeof(buffer));
                ssize_t bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);

                if (bytes_received <= 0) {
                    // 客户端断开连接
                    std::cout << "客户端断开连接。" << std::endl;
                    epoll_ctl(epoll_fd, EPOLL_CTL_DEL, client_socket, NULL);
                    close(client_socket);
                    continue;
                }

                std::cout << "收到消息: " << buffer << std::endl;

                // 转发消息给配对的客户端
                int target_client = client_map[client_socket];
                if (target_client != -1) {
                    send(target_client, buffer, strlen(buffer), 0);
                } else {
                    std::cout << "目标客户端未连接。" << std::endl;
                }
            }
        }
    }

    close(server_socket);
    return 0;
}