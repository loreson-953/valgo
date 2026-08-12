# Compiler / Options
CC = gcc
TARGET = valgo
CFLAGS = -Wall -g

# Source 
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, build/%.o, $(SRC))
INC = $(PWD)/include

include config.mk

all: $(TARGET)

$(TARGET): $(OBJ)
	@mkdir -p bin
	$(CC) -I $(INC) $(CFLAGS) $(OBJ) -o bin/$(TARGET)


build/%.o: src/%.c
	@mkdir -p build
	$(CC) -I $(INC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build/*
	rm -rf bin/*

install: $(TARGET)
	sudo cp bin/$(TARGET) /usr/local/bin
