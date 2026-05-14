CC = gcc
CFLAGS = -I/opt/homebrew/include -Wall -std=c11
LDFLAGS = -L/opt/homebrew/lib -lraylib -framework IOKit -framework Cocoa -framework OpenGL -lm
TARGET = cube
SRC = cube.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(TARGET)

run: all
	./$(TARGET)