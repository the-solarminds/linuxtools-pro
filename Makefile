CXX = g++
CXXFLAGS = -Wall -Wextra -O2 -std=c++11
LDFLAGS = 

SRC_DIR = src
BIN_DIR = bin

TARGET = $(BIN_DIR)/system_info

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(SRC_DIR)/system_info.cpp
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm -rf $(BIN_DIR)
