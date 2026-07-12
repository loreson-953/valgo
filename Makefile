# Compiler / Options
CC = gcc
TARGET = visual_algorithms
CFLAGS = -Wall -g

# Source 
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, build/%.o, $(SRC))
INC = $(PWD)/include

include config.mk

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -I $(INC) $(CFLAGS) $(OBJ) -o build/$(TARGET)


build/%.o: src/%.c
	@mkdir -p build
	$(CC) -I $(INC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build/*
