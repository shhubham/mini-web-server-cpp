#include "file_manager.h"
#include <fstream>
#include <sstream>

FileManager::FileManager(const std::string& rootDirectory) : rootDirectory_(rootDirectory) {}

std::string FileManager::serveFile(const std::string& path) {
    std::ifstream file(rootDirectory_ + path);
    if (!file) {
        return "HTTP/1.1 404 NOT FOUND\r\nContent-Length: 13\r\n\r\nFile Not Found";
    }

    std::ostringstream content;
    content << file.rdbuf();
    std::string body = content.str();

    return "HTTP/1.1 200 OK\r\nContent-Length: " + std::to_string(body.size()) +
           "\r\nContent-Type: text/html\r\n\r\n" + body;
}
