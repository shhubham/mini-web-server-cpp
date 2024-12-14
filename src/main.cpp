#include "server.h"
#include "config.h"
#include <iostream>

int main() {
    try {
        Server server(SERVER_PORT, ROOT_DIRECTORY, THREAD_POOL_SIZE);
        std::cout << "Server started on port " << SERVER_PORT << std::endl;
        server.run();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
