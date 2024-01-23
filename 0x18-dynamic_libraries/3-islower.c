/**
  * _islower - this checks if a letter is a lowercase
  * @c: accepts an int
  * Return: returns int 1 for lowercase and O othrewise
  */

int _islower(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (1);
	}

	else
		return (0);
}
