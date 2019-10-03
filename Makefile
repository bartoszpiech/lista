CC=gcc
lista: lista.c
	$(CC) lista.c -o lista -Wall -Wextra -pedantic -std=c99

clean:
	rm lista
