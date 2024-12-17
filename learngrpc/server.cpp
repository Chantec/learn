#include"data.grpc.pb.h"
#include <iostream>
#include <grpcpp/grpcpp.h>

//

class MyGreeterService: public Greeter::Service
{    
    // Status 函数执行状态
    // 参数：
    //      上下文，额外的信息 比如权限验证
    //      传递的数据
    //      返回的结果

    grpc::Status sayHello(::grpc::ServerContext* context, const ::Request* request, ::Response* response)
    {
        std::cout<<request->name()<<std::endl;
        response->set_message("hello "+request->name());
        return grpc::Status::OK;
    }
};


void runServer()
{
    // 1. 设置服务程序 
    grpc::ServerBuilder builder;
    // 不使用安全连接
    builder.AddListeningPort("0.0.0.0:50051", grpc::InsecureServerCredentials());

    // 注册服务
    MyGreeterService service;
    builder.RegisterService(&service);

    // 2. 启动服务程序
    std::unique_ptr<grpc::Server> server =  builder.BuildAndStart();
    server->Wait();
}
int main()
{
    runServer();
    return 0;
}