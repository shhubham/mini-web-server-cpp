#include "request_handler.h"
#include <iostream>

RequestHandler::RequestHandler(boost::asio::ip::tcp::socket socket, const std::string& rootDirectory)
    : socket_(std::move(socket)), rootDirectory_(rootDirectory) {}

void RequestHandler::handle() {
    try {
        HttpParser parser(socket_);
        std::string requestPath = parser.getPath();
        FileManager fileManager(rootDirectory_);
        std::string response = fileManager.serveFile(requestPath);

        boost::asio::write(socket_, boost::asio::buffer(response));
    } catch (const std::exception& e) {
        std::cerr << "Request error: " << e.what() << std::endl;
    }
}
