#include "main.h"
/**
 * append_text_to_file - appends content to an already existing file
 * @filename: the file to append the new content into
 * @text_content: the content to be appended into the filename
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	int m;
	int wr;

	if (!filename)
		return (-1);
	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);
	if (text_content)
	{
		for (m = 0; text_content[m]; m++)
		wr = write(fd, text_content, m);
		if (wr == -1)
			return (-1);
	}
	close(fd);

	return (1);
}
