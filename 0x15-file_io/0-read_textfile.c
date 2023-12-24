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
	char str[30];

	size_t count = 0;
	FILE *fp = NULL;

	if (access(filename, R_OK) == -1)
	{
		fprintf(stderr, "Error: Read permission denied\n");
		return (0);
	}
	if (filename == NULL)
		return (0);
	fp = fopen(filename, "r");
	if (fp == NULL)
		return (0);

	while ((count <= letters) && !(feof(fp)))
	{
		fgets(str, 20, fp);
		count += printf("%s", str);
	}

	fclose(fp);
	return ((count - 1));
}
