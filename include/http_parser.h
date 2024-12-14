#pragma once

#include <boost/asio.hpp>
#include <string>

class HttpParser {
public:
    explicit HttpParser(boost::asio::ip::tcp::socket& socket);
    std::string getPath();

private:
    boost::asio::ip::tcp::socket& socket_;
};
