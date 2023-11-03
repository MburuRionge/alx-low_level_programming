#include "main.h"

/**
 * create_file - create a file where to put the contents of text_content
 * @filename: name of the file if it exists
 * @text_content: the sting content to put in the file
 * Return: 1 if success, -1 if it fails
 */

int create_file(const char *filename, char *text_content)
{
	int fd;
	int tr;
	int wr;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC | S_IWUSR | S_IRUSR);
	if (fd == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (tr = 0; text_content[tr]; tr++)

	wr = write(fd, text_content, tr);

	if (wr == -1)
		return (-1);

	close(fd);

	return (1);
}
