#include <iostream>        // 引入输入输出库
#include <sys/socket.h>    // 引入 Socket 库
#include <netinet/in.h>    // 引入 Internet 地址族
#include <unistd.h>        // 引入 UNIX 标准库
#include <cstring>         // 引入字符串操作库，用于 memset()

int main() {
    int server_fd, new_socket;                 // 声明服务器 Socket 和新的客户端 Socket
    struct sockaddr_in address;                 // ip:port 结构体
    int opt = 1;                                // 设置选项
    int addrlen = sizeof(address);              // 地址结构体的大小
    const int PORT = 8081;                      // 服务器监听的端口号

    // 1创建 Socket
    // int domain type 0
    // domain:协议族 type liushi 或者 数据包
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {                       // 检查 Socket 创建是否成功
        std::cerr << "Socket creation failed!" << std::endl; // 输出错误信息
        return 1;                                // 退出程序
    }

    // 设置 Socket 选项，允许重用地址
    // 断开的时候 2 分钟时长
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // 设置服务器地址信息
    address.sin_family = AF_INET;                // 使用 IPv4 地址族
    address.sin_addr.s_addr = INADDR_ANY;       // 服务器监听的网卡 ip
    address.sin_port = htons(PORT);              // host to network short

    // 2将 Socket 绑定到指定地址和端口
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        std::cerr << "Bind failed!" << std::endl; // 输出绑定失败的信息
        return 1;                                // 退出程序
    }

    // 3 监听
    // backlog 两个队列的总长度
    // 两个队列：未完成链接：三次握手未完成，已完成：三次握手已完成
    // 一个时刻的长度

    if (listen(server_fd, 3) < 0) {
        std::cerr << "Listen failed!" << std::endl;
        return 1;                          
    }

    std::cout << "Server is listening on port " << PORT << "..." << std::endl; // 输出服务器监听状态

    while (true) {
        // 4接受客户端的连接请求
        // 默认是阻塞的
        new_socket = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
        if (new_socket < 0) {                   // 检查连接是否成功
            std::cerr << "Accept failed!" << std::endl; // 输出接受连接失败的信息
            continue;                            // 继续下一次循环
        }

        // 5 接收客户端发送的消息
        char buffer[1024] = {0};                 // 创建接收缓冲区
        ssize_t bytes_read = recv(new_socket, buffer, sizeof(buffer), 0); // 接收数据
        //  >0 字节数
        //  0   关闭
        //  -1
        if (bytes_read > 0) {                    // 检查是否成功接收数据
            std::cout << "Client: " << buffer << std::endl; // 输出客户端发送的消息

            // 发送响应消息给客户端
            const char* message = "Hello from server"; // 响应消息
            send(new_socket, message, strlen(message), 0); // 发送数据
        }

        // 关闭与客户端的连接
        close(new_socket);                        // 关闭客户端 Socket
    }

    // 关闭服务器 Socket
    close(server_fd);                            // 关闭服务器 Socket
    return 0;                                    // 正常退出程序
}
