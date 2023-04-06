#include <stdio.h>
#include "my_set.c"

void print_hello();

int main(){
    int *set;
    print_hello();
    set = get_set();
    print_set(set);
    
    free(set);
    return 0;
}

void print_hello(){
    printf("Hello!\n");
    printf("This Program lets you input integers, eliminates duplicates and then prints the set created.\n");
}