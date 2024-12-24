#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

int main() {
    int sock;
    struct sockaddr_in server;

    // 1创建 Socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        std::cerr << "Socket creation failed!" << std::endl;
        return 1;
    }

    // 设置服务器地址
    server.sin_family = AF_INET;
    server.sin_port = htons(8081);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    // 连接到服务器
    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        std::cerr << "Connection failed!" << std::endl;
        return 1;
    }

    // 发送消息
    const char* message = "Hello from client";
    send(sock, message, strlen(message), 0);

    // 接收响应
    char buffer[1024] = {0};
    recv(sock, buffer, sizeof(buffer), 0);
    std::cout << "Server: " << buffer << std::endl;

    // 关闭 Socket
    close(sock);
    return 0;
}