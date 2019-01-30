CC=gcc
CFLAGS=-I.

shell: shell.o shell_functions.o
	$(CC) -o shell shell.o shell_functions.o
