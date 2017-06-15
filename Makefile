CC = gcc
OBJECTS = encode.o
CFLAGS = -std=c99

.PHONY: all
all: $(OBJECTS) encode

encode: encode.o
	$(CC) -o encode $(OBJECTS)
encode.o: encode.c
	$(CC) $(CFLAGS) -c encode.c

.PHONY: clean
clean:
	rm encode.o
