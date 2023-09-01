#include <stdlib.h>
#include <stdio.h>

/**
 * _atoi - checks if the arguments are integers
 * @t: pointer to a variable
 * Return: (n)
 */

int _atoi(char *t)
{
	int i, d, n, len, f, digit;

	i = 0;
	d = 0;
	n = 0;
	len = 0;
	f = 0;
	digit = 0;

	while (i < len && f == 0)
	{
		if (t[i] == '-')
		{
			++d;
		}

		if (t[i] >= '0' && t[i] <= '9')
		{
			digit = t[i] - '0';

			if (d % 2)
			{
				digit = -digit;
			}
			n = n * 10 + digit;

			f = i;

			if (t[i + 1] < '0' || t[i + 1] > '9')
			{
				break;
			}
			f = 0;
		}
		i++;
	}
	if (f == 0)
	{
		return (0);
	}
	return (n);
}
/**
 * main - provide two arguments
 * @argc: represents the number of arguments
 * @argv: its an array of strings that stores the number of arguments
 * Return: 0;
 */

int main(int argc, char *argv[])
{
	int product, num1, num2;

	if (argc < 3 || argc > 3)
	{
		printf("Error\n");
		return (1);
	}
	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);

	product = num1 * num2;
	printf("%d\n", product);

	return (0);
}
