my_app: main.o my_string.o
	gcc -ansi -Wall -pedantic -g lib/main.o lib/my_string.o -o bin/my_app
main.o: src/main.c src/my_string.h src/data.h
	gcc -c -ansi -Wall -pedantic src/main.c -o lib/main.o
my_string.o: src/my_string.c src/my_string.h
	gcc -c -ansi -Wall -pedantic src/my_string.c -o lib/my_string.o

