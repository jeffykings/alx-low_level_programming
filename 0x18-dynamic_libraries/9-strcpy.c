/**
  * _strcpy -  copies the string pointed to by src, including the terminating
  * null byte (\0), to the buffer pointed to by dest.
  * @dest: pointer to a string
  * @src: pointer to a string
  * Return: pointer to a sting
  */

char *_strcpy(char *dest, char *src)
{
	int i, j;

	for (i = 0; src[i] != '\0'; i++)
	{
	}

	for (j = 0; j <= (i + 1); j++)
	{
		dest[j] = src[j];
	}

	return (dest);
}
