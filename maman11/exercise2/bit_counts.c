#include <stdio.h>
#define ULONG_SIZE 64

unsigned long read_binary();
int count_bits(unsigned long num);

int main()
{
	unsigned long num;
	printf("Hello! This program counts the number of active bits in even places.\n");
	printf("Please Enter a binary number!: ");
	num = read_binary();

    printf("\nresult: %ld", num);
    return 0;
}

unsigned long read_binary(){
	int i;
	char num_s[ULONG_SIZE];
	unsigned long num = 0;
	scanf("%64[01]", num_s);
	printf("The number read is %s\n", num_s);
	for (i = 0; num_s[i]; i++) {
        num = (num << 1) | (num_s[i] - '0');
    }
	return num;
}


int count_bits(unsigned long num){
    int i, sum;
    sum = 0;
    for(i = LONG_SIZE - 1; i >= 0; --i){
        if((num >> i) & 1)
            sum++;
		num >> 1;
    }
    return sum;
}
