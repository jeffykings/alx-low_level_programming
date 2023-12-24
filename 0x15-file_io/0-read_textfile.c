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
	ssize_t o, r, w;

	str = malloc(letters * sizeof(char));
	if (str == NULL)
		return (0);

	if (filename == NULL)
		return (0);

	o = open(filename, O_RDONLY);
	r = read(o, str, letters);
	w = write(1, str, r);

	if (o == -1 || r == -1 || w == -1 || r != w)
	{
		free(str);
		return (0);
	}
	close(o);
	free(str);
	return (w);
}
