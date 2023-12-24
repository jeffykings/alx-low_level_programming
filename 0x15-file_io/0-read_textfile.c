#include "main.h"

/**
  * read_textfile - Reads a text file and prints it to POSIX stdout.
  * @filename: A pointer to the name of the file.
  * @letters: The number of letters the
  *	      function should read and print.
  * Return: If the function fails or filename is NULL - 0.
  *	      O/w - the actual number of bytes the function can read an    d print.
  */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *str;

	size_t count;
	FILE *fp = NULL;

	str = malloc(letters * sizeof(char));
	if (str == NULL)
		return (0);

	if (filename == NULL)
		return (0);
	fp = fopen(filename, "r");
	if (fp == NULL)
		return (0);

	count = fread(str, sizeof(char), letters, fp);
	fwrite(str, sizeof(char), count, stdout);
	fclose(fp);
	free(str);
	return (count);
}
