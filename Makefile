CC = gcc
TARGET = visual_algorithms
CFLAGS = -Wall -g
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

include config.mk

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

clean:
	rm -f $(TARGET) *.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
