#pragma once

#include <iostream>
#include <string>

#include <boost/asio.hpp>

class TTCPClient
{
public:
    TTCPClient(boost::asio::io_context& io_context,
               const std::string& host,
               short port
    );

    void sendMessage(const std::string& message);

private:
    boost::asio::ip::tcp::socket socket_;
    boost::asio::ip::tcp::resolver resolver_;
};
