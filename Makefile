SRC_DIR = src
BUILD_DIR = build/debug
CC = gcc
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_NAME = play
INCLUDE_PATH = -Iinclude
LIBRARY_PATH = -Llib
COMPILER_FLAGS = -g -Wall -Wextra -pedantic -std=c11
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf

all:
	$(CC) $(COMPILER_FLAGS) $(LINKER_FLAGS) $(INCLUDE_PATH) $(LIBRARY_PATH) $(SRC_FILES) -o $(BUILD_DIR)/$(OBJ_NAME)