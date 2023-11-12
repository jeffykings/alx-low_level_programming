/**
  * rot13 - encodes a string using rot13.
  * @str: accepts strings
  * Return: pointer to string
  */

char *rot13(char *str)
{
	int i, current, base;


	for (i = 0; str[i] != '\0'; i++)
	{
		current = str[i];

		for (; (current >= 'A' && current <= 'Z') || (current >= 'a' && current <= 'z');)
		{
			if (current >= 'A' && current <= 'Z')
			{
				base = 'A';
				str[i] = (current - base + 13) % 26 + base;
				break;
			}
			else
			{
				base = 'a';
				str[i] = (current - base + 13) % 26 + base;
				 break;
			}
		}
	}
	return (str);
}
