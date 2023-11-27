CC := g++
CFLAGS := -Wall -Wextra -std=c++11
LDFLAGS := -lraylib

SRC_DIR := src
BUILD_DIR := build
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))

.PHONY: all clean

all: $(BUILD_DIR)/main

$(BUILD_DIR)/main: $(OBJ_FILES)
	@mkdir -p $(BUILD_DIR)
	$(CC) $^ $(LDFLAGS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)