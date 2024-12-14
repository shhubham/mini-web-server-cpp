#include "http_parser.h"
#include <iostream>
#include <sstream>

HttpParser::HttpParser(boost::asio::ip::tcp::socket& socket) : socket_(socket) {}

std::string HttpParser::getPath() {
    boost::asio::streambuf buffer;
    boost::asio::read_until(socket_, buffer, "\r\n");
    std::istream stream(&buffer);

    std::string method, path, version;
    stream >> method >> path >> version;

    if (path == "/") {
        path = "/index.html";
    }
    return path;
}
