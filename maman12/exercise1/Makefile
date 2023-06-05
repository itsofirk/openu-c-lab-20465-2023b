my_set: main.o my_set.o
	gcc -ansi -Wall -pedantic -g lib/main.o -o bin/my_set
main.o: src/main.c my_set.o
	gcc -c -ansi -Wall -pedantic src/main.c -o lib/main.o
my_set.o: src/my_set.c src/consts.h 
	gcc -c -ansi -Wall -pedantic src/my_set.c -o lib/my_set.o

