/**
  * _strncat - concatenates two strings. is similar to the _strcat function,
  * except that it will use at most n bytes from "src".
  * @dest: destination pointer to string
  * @src: source pointer to string
  * @n: integer. number of characters to copy
  * Return: pointer to string
  */

char *_strncat(char *dest, char *src, int n)
{
	int len1, j;

	for (len1 = 0; dest[len1] != 0; len1++)
	{
	}

	for (j = 0; j < n && src[j] != '\0'; j++)
	{
		dest[len1 + j] = src[j];
	}

	return (dest);
}
