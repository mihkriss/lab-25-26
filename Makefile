#!/bin/make
CC = gcc
CCFLAGS = -g -Wall -std=c99

SRC = list.c main.c sort.c 
PROG = main

build:
$(CC) $(CFLAGS) $(SRC) -o $(PROG)

clean:
rm $(PROG)

