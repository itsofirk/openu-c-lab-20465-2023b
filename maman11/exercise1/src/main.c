#include <stdio.h>
#include "data.h"
#include "my_string.h"
#define MENU_SIZE 5
#define STDIN_EMPTY feof(stdin)

const char *options[MENU_SIZE] = {"Exit", "Print menu", "my_strcmp", "my_strncmp", "my_strchr"};

void print_welcome();
void print_menu();
void read_string(char s[]);
char get_char();
int get_int();
int get_selection();
void execute_selection();
void demonstrate_strcmp();
void demonstrate_strncmp();
void demonstrate_strchr();

/* This program demonstrates three string functions: strcmp, strncmp, strchr*/
int main() {
	int selection;
	print_welcome();
	print_menu();
	selection = get_selection();
	while(selection >= -1){
		execute_selection(selection);
		selection = get_selection();
	}
	printf("\n");
	return 0;
}

void print_welcome(){
	printf("Welcome!\n");
	printf("This program deomstrates the behavior of 3 string functions.\n\n");
}

void print_menu(){
	int i;
	for(i=0; i<MENU_SIZE; i++)
		printf("%2d) %s\n", i-1, options[i]);
}

int get_selection(){
	int stn;
	printf("What would you like to do (Enter 0 for menu): ");
	scanf("%d", &stn);
	printf("\n");
	return stn;
}

void execute_selection(int stn){
	switch (stn){
		case -1:
			printf("Goodbye!");
			break;
		case 0:
			print_menu();
			break;
		case 1:
			demonstrate_strcmp();
			break;
		case 2:
			demonstrate_strncmp();
			break;
		case 3:
			demonstrate_strchr();
			break;
		default:
			printf("Your selection seems to be wrong.\n");
			break;
	}
}

void read_string(char s[]){
	if(!STDIN_EMPTY){
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



