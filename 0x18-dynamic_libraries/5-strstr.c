#include <stdio.h>
/**
  * _strstr - locates a substring.
  * @haystack:  A pointer to the null-terminated string to be searched.
  * @needle: A pointer to the null-terminated string representing the
  * substring to search for.
  * Return: a pointer to the beginning of that occurrence in the haystack.
  */

char *_strstr(char *haystack, char *needle)
{
	char *tempHaystack = haystack;
	char *tempNeedle = needle;

	while (*haystack != '\0')
	{

	while (*tempHaystack != '\0' && *tempNeedle != '\0'
			&& *tempHaystack == *tempNeedle)
	{
		tempHaystack++;
		tempNeedle++;
	}

	if (*tempNeedle == '\0')
	{
		return (haystack);
	}

	haystack++;
	}

	return (NULL);
}
