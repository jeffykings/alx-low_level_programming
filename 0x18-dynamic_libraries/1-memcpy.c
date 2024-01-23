/**
  * _memcpy - copies memory area.
  * @dest: destination to be copied to. string pointer.
  * @src: source to be copied from. string pointer.
  * @n: number of bytes to be copied
  */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		*(dest + i) = *(src + i);
	}
	return (dest);
}
