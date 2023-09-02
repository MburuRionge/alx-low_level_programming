#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "main.h"

/**
 * check_num - checks if the string is an integer
 * @str: its an array of str
 * Return: 1
 */


int check_num(char *str)
{
	unsigned int count;
	count = 0;

	while (count < strlen(str))
	{
		if (!isdigit(str[count]))
		{
			return (0);
		}
		count++;
	}
	return (1);
}

/**
 * main - contains two arguments
 * @argc: represents the number of arguments
 * @argv:an arrayof strings
 * Return: 0
 */


int main(int argc, char *argv[])
{
	int count;
	int ptr;

	int sum = 0;
	count = 1;
	while (count < argc)
	{
		if (check_num(argv[count]))
		{
			ptr = atoi(argv[count]);
			sum += ptr;
		}
		else
		{
			printf("Error\n");

			return (1);
		}
		count++;
	}
	printf(" % d\n", sum);
	return (0);
}
