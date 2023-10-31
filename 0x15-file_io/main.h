#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int _putchar(char c);
ssize_t read_textfile(const char *filename, ssize_t letters);
int append_text_to_file(const char *filename, char *text_content);
int create_file(const char *filename, char *text_content);

#endif
