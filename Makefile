CC = gcc
FLAGS = -Wall -Wextra -g

example:
	$(CC) -o example example.c  $(FLAGS)
	./example
	rm example

release:
	$(CC) -o example example.c -O3 -DNDEBUG $(FLAGS)
	./example
	rm example