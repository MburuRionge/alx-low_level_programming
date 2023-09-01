#include "main.h"
#include <stdio.h>

/**
 * main - prints all the arguments it receives
 * @argc: represents the number of arguments passed onto the program
 * @argv: stores all the arguments in the program
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	return (0);
}
