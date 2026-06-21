// TCPServer.cpp:
// 

#include "TCPServer.h"

int main()
{
    boost::asio::io_context io_context;

    TTCPServer server(io_context, 1234);

    server.start();


    return 0;
}
