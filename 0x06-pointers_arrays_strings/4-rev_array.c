/**
  * reverse_array - reverses the content of an array of integers.
  * @a: pointer to integer array to be reversed
  * @n: size of array
  * Return: Nothing
  */

void reverse_array(int *a, int n)
{
	int i, swap = 0;

	for (i = 0; i < n / 2; i++)
	{
		swap = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = swap;
	}
}
