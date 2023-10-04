#include "main.h"

/**
 * read_textfile - Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: w- actual number of bytes read and printed
 * 0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t ph;
	ssize_t ti;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	ti = read(fd, buf, letters);
	ph = write(STDOUT_FILENO, buf, ti);

	free(buf);
	close(fd);
	return (ph);
}

