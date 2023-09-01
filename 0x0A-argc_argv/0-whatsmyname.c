#include <stdio.h>

/**
 * main - used to introduce two parameters argc and argv
 * @argc: used represent the number of arguments
 * @argv: its an array of strings containing the number of arguments
 * Return: 0;
 */

int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", *argv);
	return (0);
}
