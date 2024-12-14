#pragma once

#include <string>

class FileManager {
public:
    explicit FileManager(const std::string& rootDirectory);
    std::string serveFile(const std::string& path);

private:
    std::string rootDirectory_;
};
