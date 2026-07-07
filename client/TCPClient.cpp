#include <string>

#include "TCPClient.h"


TTCPClient::TTCPClient(boost::asio::io_context& io_context,
                       const std::string& host,
                       short port)
    : socket_(io_context), resolver_(io_context)
{
    boost::asio::ip::tcp::resolver::results_type endpoints =
        resolver_.resolve(host, std::to_string(port)
    );

    boost::asio::connect(socket_,
                         endpoints
    );
}

void TTCPClient::sendMessage(const std::string& message)
{
    boost::asio::write(socket_,
                       boost::asio::buffer(message + '\n')
    );

    boost::asio::streambuf buffer;


    boost::asio::read_until(socket_,
                            buffer,
                            '\n'
    );


    std::istream istrm(&buffer);
    std::string response;

    std::getline(istrm, response);
    std::cout << "Response from the server: " << response << std::endl;
}
