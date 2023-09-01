#include <stdio.h>
#include "main.h"
/**
 * main - have two arguments
 * @argv: array of strings containing the arguments
 * @argc: reprents the number of arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{

	(void)argv;

	printf("%d\n", argc - 1);
	return (0);
}
