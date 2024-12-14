#include "server.h"
#include <iostream>

Server::Server(int port, const std::string& rootDirectory, size_t threadPoolSize)
    : ioContext_(),
      acceptor_(ioContext_, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port)),
      rootDirectory_(rootDirectory) {

    for (size_t i = 0; i < threadPoolSize; ++i) {
        threadPool_.emplace_back([this]() {
            ioContext_.run();
        });
    }
}

void Server::run() {
    doAccept();
    ioContext_.run();
}

void Server::doAccept() {
    auto socket = std::make_shared<boost::asio::ip::tcp::socket>(ioContext_);
    acceptor_.async_accept(*socket, [this, socket](const boost::system::error_code& ec) {
        if (!ec) {
            std::make_shared<RequestHandler>(std::move(*socket), rootDirectory_)->handle();
        } else {
            std::cerr << "Accept error: " << ec.message() << std::endl;
        }
        doAccept();
    });
}
