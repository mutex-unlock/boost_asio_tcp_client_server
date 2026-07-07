# CMakeLists.txt главной директории проекта "boost_asio_tcp_client_server".

cmake_minimum_required(VERSION 4.3)

project(boost_asio_tcp_client_server)

# настраиваем стандарт языка C++20
set(CMAKE_CXX_STANDART 20)
set(CMAKE_CXX_STANDART_REQUIRED ON)

find_package(Boost 1.91.0 REQUIRED COMPONENTS)


add_executable(server
    server/TCPServer.cpp
    server/main.cpp
)

target_include_directories(server PRIVATE ${Boost_INCLUDE_DIRS})


add_executable(client
    client/TCPClient.cpp
    client/main.cpp
)

target_include_directories(client PRIVATE ${Boost_INCLUDE_DIRS})
