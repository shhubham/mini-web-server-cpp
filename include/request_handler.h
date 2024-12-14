#pragma once

#include <boost/asio.hpp>
#include <string>
#include "http_parser.h"
#include "file_manager.h"

class RequestHandler {
public:
    RequestHandler(boost::asio::ip::tcp::socket socket, const std::string& rootDirectory);
    void handle();

private:
    boost::asio::ip::tcp::socket socket_;
    std::string rootDirectory_;
};
