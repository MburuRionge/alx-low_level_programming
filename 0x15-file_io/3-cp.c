#include "main.h"

/**
 * error_file - checks if files can be opened
 * @file_from: where we get the contents of the file from
 * @file_to: where we get contents into the file
 * @argv: arguments vector
 * Return: no return
 */
void error_file(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - check the code for Holberton School students
 * @argc: number of arguments
 * @argv: Arguments vector
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, err_close;
	ssize_t rd, wr;
	char buf[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage:cp file_from file_to");
		exit(97);
	}
	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_file(file_from, file_to, argv);

	rd = 1024;
	while (rd == 1024)
	{
		rd = read(file_from, buf, 1024);
		if (rd == -1)
			error_file(-1, 0, argv);
		wr = write(file_to, buf, rd);
		if (wr == -1)
			error_file(0, -1, argv);
	}

	err_close = close(file_from);
	if (err_close == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}
	return (0);
}
