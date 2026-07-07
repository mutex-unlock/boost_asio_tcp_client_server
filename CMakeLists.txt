# CMakeLists.txt главной директории проекта "boost_asio_tcp_client_server".

cmake_minimum_required(VERSION 4.3)

project(boost_asio_tcp_client_server)

# настраиваем стандарт языка C++20
set(CMAKE_CXX_STANDART 20)
set(CMAKE_CXX_STANDART_REQUIRED ON)

find_package(Boost 1.66 REQUIRED COMPONENTS system)


add_executable(server
    server/TCPServer.cpp
    server/main.cpp
)
target_link_libraries(server PRIVATE Boost::system)
target_include_directories(server PRIVATE include)


add_executable(client
    client/TCPClient.cpp
    client/main.cpp
)
target_link_libraries(client PRIVATE Boost::system)
target_include_directories(client PRIVATE include)
