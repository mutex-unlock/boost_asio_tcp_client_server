#include <iostream>
#include <string>

#include "TCPServer.h"



TTCPServer::TTCPServer(boost::asio::io_context& io_context,
                       short port)

    : acceptor_(io_context,
                boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(),
                                                port)
                )
{

}

void TTCPServer::start()
{
    while (true)
    {
        std::cout << "The server is running. Waiting for connection..." << std::endl;

        acceptConnection();
    }
}


void TTCPServer::acceptConnection()
{
    boost::asio::ip::tcp::socket socket(acceptor_.get_executor());

    acceptor_.accept(socket);
    std::cout << "The client has connected!" << std::endl;


    while (true)
    {
        boost::asio::streambuf buffer;
        boost::system::error_code errorCode;

        boost::asio::read_until(socket,
                                buffer,
                                '\n',
                                errorCode
        );

        if (errorCode == boost::asio::error::eof)
        {
            std::cout << "Client disconnected\n";
            break;
        }
        else if (errorCode)
        {
            throw boost::system::system_error(errorCode);
        }


        std::istream istrm(&buffer);
        std::string message;

        std::getline(istrm, message);
        std::cout << "Message received: " << message << std::endl;


        boost::asio::write(socket,
                           boost::asio::buffer("Message received!\n")
        );

    }   // end infinity while
}
