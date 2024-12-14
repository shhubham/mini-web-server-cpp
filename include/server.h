#pragma once

#include <boost/asio.hpp>
#include <string>
#include <vector>
#include "request_handler.h"

class Server {
public:
    Server(int port, const std::string& rootDirectory, size_t threadPoolSize);
    void run();

private:
    void doAccept();

    boost::asio::io_context ioContext_;
    boost::asio::ip::tcp::acceptor acceptor_;
    std::vector<std::thread> threadPool_;
    std::string rootDirectory_;
};
