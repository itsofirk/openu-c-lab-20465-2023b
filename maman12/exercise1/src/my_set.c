#include <stdio.h>
#include <stdlib.h>
#define INITIAL_SIZE 5
#define ENLARGE_SIZE 5

int* get_set();
void print_set(int* set);

int main() {
    int capacity = INITIAL_SIZE; // initial capacity of the array
    int size = 0; // current size of the array
    int number;
    char buffer[256];
    int *numbers = malloc(capacity * sizeof(int)); // allocate memory for the array
    
    printf("Enter integers separated by spaces or new lines.\n * Press enter twice to end input:\n");
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        // check if the user pressed enter twice to end input
        if (buffer[0] != '\n') {
            char *ptr = buffer;
            while (sscanf(ptr, "%d", &number)) {
                // check if the number is already in the array
                int found = 0;
                for (int i = 0; i < size; i++) {
                    if (numbers[i] == number) {
                        found = 1;
                        break;
                    }
                }
                
                // if the number is not in the array, add it
                if (!found) {
                    // expand the array if necessary
                    if (size == capacity) {
                        capacity *= 2;
                        numbers = realloc(numbers, capacity * sizeof(int));
                    }
                    
                    // add the number to the array
                    numbers[size++] = number;
                }
                
                // find the next integer in the input string
                ptr += strspn(ptr, "0123456789");
                ptr += strspn(ptr, " \t\n"); // skip whitespace
            }
        }
    }
    
    // print the unique integers in the order they were input
    printf("Unique integers entered:\n");
    for (int i = 0; i < size; i++) {
        printf("%d\n", numbers[i]);
    }
    
    // free the memory allocated for the array
    free(numbers);
    
    return 0;
}
