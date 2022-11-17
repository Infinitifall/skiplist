CC=gcc
CFLAGS = -Wall -O

all: example_simple example_cli

example_simple: example_simple.o skiplist.o
	$(CC) $(CFLAGS) -o example_simple example_simple.o skiplist.o

example_cli: example_cli.o skiplist.o
	$(CC) $(CFLAGS) -o example_cli example_cli.o skiplist.o

example_simple.o: example_simple.c skiplist.h
	$(CC) $(CFLAGS) -c example_simple.c skiplist.h

example_cli.o: example_cli.c skiplist.h
	$(CC) $(CFLAGS) -c example_cli.c skiplist.h

skiplist.o: skiplist.c skiplist.h
	$(CC) $(CFLAGS) -c skiplist.c skiplist.h

clean:
	$(RM) example_cli
	$(RM) example_simple
	$(RM) example_cli.o
	$(RM) example_simple.o
	$(RM) skiplist.o