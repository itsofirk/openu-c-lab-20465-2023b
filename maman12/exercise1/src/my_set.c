#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "consts.h"
#define CAPACITY 5
#define ENLARGE_SIZE 5

int *get_set();
void print_set(int arr[]);
int arr_contains(int arr[], int size, int number);
char *next_int(char *buff);
int has_non_numeric_chars(char *buff);

int *get_set()
{
    int capacity = CAPACITY; /*  initial capacity of the array */
    int size = 0;            /*  current size of the array */
    int number;
    char buffer[256];
    char *ptr;
    int *numbers = malloc(capacity * sizeof(int)); /*  allocate memory for the array */

    printf("Enter integers separated by spaces or new lines.\n * Press enter twice to end input:\n");
    while (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        /*  check if the user pressed enter twice to end input */
        if (buffer[0] == '\n')
            return numbers;
        ptr = buffer;
        if (has_non_numeric_chars(ptr))
                printf("Non numeric values found. skipping input.\n");
        else
        {
            while (sscanf(ptr, "%d", &number) == 1)
            {
                /*  if the number void print_set(int* set) print_set(int* set)void print_set(int* set)is not in the array, add it */
                if (!arr_contains(numbers, size, number))
                {
                    /*  expand the array if necessary */
                    if (size == capacity)
                    {
                        capacity += ENLARGE_SIZE;
                        numbers = realloc(numbers, capacity * sizeof(int));
                    }
                    numbers[size++] = number;
                }
                ptr = next_int(ptr);
            }
        }
    }
    return numbers;
}

/*  check if arr contains a number */
int arr_contains(int arr[], int size, int number)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == number)
            return TRUE;
    }
    return FALSE;
}

/*  print an integers array */
void print_set(int arr[])
{
    int i;
    printf("Unique integers entered:\n");
    if (arr[0])
        printf("%d", arr[0]);
    for (i = 1; arr[i]; i++)
    {
        printf(", %d", arr[i]);
    }
    printf("\n");
}

/*  find the next integer in the input string */
char *next_int(char *buff)
{
    buff += strspn(buff, "0123456789"); /* skip over non-numeric characters*/
    buff += strspn(buff, " \t\n");      /* skip over whitespace */
    return buff;
}

/* count non-numeric chars in the input string */
int has_non_numeric_chars(char *buffer) {
    while (*buffer != '\0') {
        if (!isdigit(*buffer) && !isspace(*buffer)) {
            return TRUE;  /* non-numeric char found */
        }
        buffer++;
    }
    return FALSE;  /* no non-numeric chars found */
}