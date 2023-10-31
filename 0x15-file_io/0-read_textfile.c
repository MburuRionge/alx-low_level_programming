#include "main.h"

/**
 * read_textfile - Read text print to STDOUT
 * @filename: file where text is read from
 * @letters: number of letters to be read from
 * Return: actual number of bytes read and printed else 0 when function
 * call fails or filename is NULL
 */

ssize_t read_textfile(const char *filename, ssize_t letters)
{
	ssize_t fd;
	ssize_t wr;
	ssize_t rd;
	char *buf;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	rd = read(fd, buf, letters);
	wr = write(STDOUT_FILENO, buf, rd);

	free(buf);
	close(fd);
	return (wr);
}
