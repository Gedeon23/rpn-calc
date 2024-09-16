# Variables
CC = clang
CFLAGS = -Wall -g
TARGET = calc
SRC = main.c
LINK = -lncurses

# Rule to compile
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LINK)

# Clean rule to remove the binary
clean:
	rm -f $(TARGET)

run: 
	make clean
	make
	./$(TARGET)
