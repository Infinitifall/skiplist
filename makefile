CC=gcc
CFLAGS = -g -Wall
TARGET = main_example

all: main_example

main_example: main_example.o skiplist.o
	$(CC) $(CFLAGS) -o $(TARGET) main_example.o skiplist.o

main_example.o: main_example.c src/skiplist.h
	$(CC) $(CFLAGS) -c main_example.c src/skiplist.h

skiplist.o: src/skiplist.c src/skiplist.h
	$(CC) $(CFLAGS) -c src/skiplist.c src/skiplist.h

clean:
	$(RM) $(TARGET)
	$(RM) main_example.o
	$(RM) skiplist.o