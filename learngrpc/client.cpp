#include "data.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include <iostream>

// 联结服务器
// 调用函数

void runClient() {
    //构建一个连接通道
    //创建一个远程调用代理
    //通过代理调用远程函数

    std::shared_ptr<grpc::Channel> channel= grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials());
    std::unique_ptr< Greeter::Stub> stub=Greeter::NewStub(channel);

    grpc::ClientContext context;// 可以设置执行时间等参数
    Request request;
    request.set_name("liang zi chao");
    request.set_age(23);
    Response result;
    grpc::Status status= stub->sayHello(&context, request, &result);
    if (status.ok()) {
        std::cout << result.message() << std::endl;

    }
    else {
        std::cout << "RPC failed" << std::endl;
    }

}
int main()
{
    runClient();
}