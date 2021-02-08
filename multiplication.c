#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

void multiply(int base);
int *multiplication_table(int base);
void print_table(int *mult_table, int base);

int main(void)
{
	int base;

	for (base = 1; base <= TABLE_SIZE; base++)
		multiply(base);

	base = 42;
	multiply(base);
	
	base = 1337;
	multiply(base);
	
	return EXIT_SUCCESS;
}

void multiply(int base)
{
	int *mult_table;

	mult_table = multiplication_table(base);

	print_table(mult_table, base);
}

int *multiplication_table(int base)
{
	int *mult_table = malloc(sizeof(int) * TABLE_SIZE);

	if (mult_table == NULL) 
	{
		fprintf(stderr, "Malloc: Failure to allocate memory\n");
		exit(1);
	}

	int *ptr = mult_table;

	for(int i = 1; i <= TABLE_SIZE; i++)
	{
		*ptr = base * i;
		ptr++;
	}

	return mult_table;
}

void print_table(int *mult_table, int base)
{
	printf("---%d GANGEN---\n", base);
	for (int i = 0; i < TABLE_SIZE; i++)
        {
        	printf("%d x %d = %d\n", base, i + 1, mult_table[i]);        
        }
	printf("\n");
	
	free(mult_table);
}




