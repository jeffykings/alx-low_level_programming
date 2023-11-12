/**
  * rot13 - encodes a string using rot13.
  * @str: accepts strings
  * Return: pointer to string
  */

char *rot13(char *str)
{
	int i, j;

	char array1[] = "ABCDEFGHIJKLMabcdefghijklm";
	char array2[] = "NOPQRSTUVWXYZnopqrstuvwxyz";

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; (str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'); j++)
		{
			if (str[i] == array1[j])
			{
				str[i] = array2[j];
				break;
			}
			else
			{
				str[i] = array1[j];
			}
		}
	}
	return (str);
}
