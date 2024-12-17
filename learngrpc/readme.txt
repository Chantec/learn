# protoc
protoc --cpp_out=. data.proto
protoc --grpc_out=. --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` data.proto

#编译
g++ server.cpp data.grpc.pb.cc data.pb.cc  -lgrpc++ -lgrpc -lprotobuf -lpthread -ldl -o server 
g++ client.cpp data.grpc.pb.cc data.pb.cc  -lgrpc++ -lgrpc -lprotobuf -lpthread -ldl -o client
