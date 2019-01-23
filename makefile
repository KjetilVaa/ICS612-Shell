CC=gcc
CFLAGS=-I.

my_shell: shell.o shell_functions.o
	$(CC) -o my_shell shell.o shell_functions.o
