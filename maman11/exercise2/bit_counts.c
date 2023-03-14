#include <stdio.h>
#define LONG_SIZE sizeof(unsigned long) * 8

void print_binary(unsigned long num);
int count_bits(unsigned long num);

int main()
{
    unsigned long num = 0b10010100;
    int res;
    print_binary(num);
    res = count_bits(num);
    printf("\nresult: %d", res);
    return 0;
}

void print_binary(unsigned long num) {
  // Determine the number of bits in an unsigned long
  int num_bits = sizeof(unsigned long) * 8;
  // Loop through each bit of the number and print it as 0 or 1
  for (int i = num_bits - 1; i >= 0; i--) {
    printf("%ld", (num >> i) & 1);
  }
  printf("\n");
}

int count_bits(unsigned long num){
    int i, sum;
    sum = 0;
    for(i=LONG_SIZE-1; i>=0; i-=2){
        if((num >> i) & 1)
            sum++;
    }
    return sum;
}
