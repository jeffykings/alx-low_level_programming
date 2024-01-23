/**
  * _strcat -  concatenates two strings.
  * @dest: destination ponting to a string
  * @src:  source pointing to a sting
  * Return: pointer
  */

char *_strcat(char *dest, char *src)
{
	int j, len2, len;

	for (len = 0; dest[len] != '\0'; len++)
	{
	}

	for (len2 = 0; src[len2] != '\0'; len2++)
	{
	}

	for (j = 0; j <= len2; j++)
	{
		dest[len + j] = src[j];
	}

	return (dest);
}
