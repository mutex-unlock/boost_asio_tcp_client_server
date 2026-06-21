#pragma once

#include <iostream>

#include <boost/asio.hpp>

class TTCPServer
{
public:
    TTCPServer(boost::asio::io_context& io_context, short port);

    void start();

private:
    boost::asio::ip::tcp::acceptor acceptor_;

    void acceptConnection();
};
