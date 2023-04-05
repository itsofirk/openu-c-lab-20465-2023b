#include <stdio.h>

void print_hello();

void main(){
    print_hello();
    get_set();
    print_set();
}

void print_hello(){
    printf("Hello!\n");
    printf("This Program lets you input integers, eliminates duplicates and then prints the set created.\n");
    printf("Press enter to start...\n");
    getchar();
}