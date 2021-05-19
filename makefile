CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -g
SRC = list.c sort.c main.c
PROG = lab26

build:
	$(CC) $(CFLAGS) $(SRC) -o $(PROG)

clean:
	rm $(PROG)

