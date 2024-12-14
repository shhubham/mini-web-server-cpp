CXX = g++
CXXFLAGS = -std=c++17 -pthread -lboost_system -I./include
SRC = src/main.cpp src/server.cpp src/request_handler.cpp src/http_parser.cpp src/file_manager.cpp
TARGET = web_server

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
