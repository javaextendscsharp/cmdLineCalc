TARGET = pointers
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic

pointers: pointers.c
	$(CC) pointers.c -o pointers $(CFLAGS) 