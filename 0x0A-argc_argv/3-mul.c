#include <stdlib.h>
#include <stdio.h>

/**
 * main - provide two arguments
 * @argc: represents the number of arguments
 * @argv: its an array of strings that stores the number of arguments
 * Return: 0;
 */

int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	else
	{
		int a, b, product;

		a = atoi(argv[1]);
		b = atoi(argv[2]);

		product = a * b;

		printf("The product of %d and %d is %d\n", a, b, product);
	}
	return (0);
}
