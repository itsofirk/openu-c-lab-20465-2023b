#include <stdio.h>
#include "data.h"
#include "my_string.h"

void print_welcome();
void read_string(char s[]);
char get_char();
int get_int();

void demonstrate_strcmp();
void demonstrate_strncmp();
void demonstrate_strchr();

/* This program demonstrates three string functions: strcmp, strncmp, strchr*/
int main() {
	print_welcome();
	demonstrate_strcmp();
	demonstrate_strncmp();
	demonstrate_strchr();
	printf("\n");
	return 0;
}

void print_welcome(){
	printf("Welcome!\n");
	printf("We will go over a few string functions.\n");
}

void read_string(char s[]){
	if(!feof(stdin)){
		printf("Please enter a word (maximum %d characters): ", MAX_STR);
	}
	scanf("%s", s);
}

char get_char(){
	char c;
	printf("Please enter one character: ");
	scanf(" %c", &c);
	return c;
}

int get_int(){
	int x;
	printf("Please enter an integer: ");
	scanf("%d", &x);
	return x;
}

void demonstrate_strcmp(){
	char s1[MAX_STR], s2[MAX_STR];
	printf("\nWe will now compare two strings\n");
	read_string(s1);
	read_string(s2);
	printf("When comparing (%s) to (%s) we get: %d\n", s1, s2, my_strcmp(s1, s2));
}

void demonstrate_strncmp(){
	char s1[MAX_STR], s2[MAX_STR];
	int n;
	printf("\nWe will now compare two strings to a certain index.\n");
	read_string(s1);
	read_string(s2);
	n = get_int();
	printf("When comparing (%s) to (%s), until the %dth character, we get: %d\n", s1, s2, n, my_strncmp(s1, s2, n));
}

void demonstrate_strchr(){
	char s1[MAX_STR], c;
	int i;
	printf("\nWe will now find a character in a string.\n");
	/*char c = get_char();*/
	read_string(s1);
	c = get_char();
	i = my_strchr(s1, c);
	if (i >= 0)
		printf("(%c) is found within (%s), its location is %d\n", c, s1, i);
	else
		printf("(%c) is not found within (%s)\n", c, s1);
}



