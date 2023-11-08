/**
  * leet -  encodes a string into 1337.
  * @str: pointer to a string
  * Return: pointer to a string
  */

char *leet(char *str)
{
	int j, i;

	char check[] = "AETOL";
	char symbol[] = "43701";

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; check[j] != '\0'; j++)
		{
			if ((str[i] == check[j]) || (str[i] == check[j] + 32))
			{
				str[i] = symbol[j];
			}
		}
	}
	return (str);
}
