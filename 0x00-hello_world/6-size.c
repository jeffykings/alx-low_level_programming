#include <stdio.h>

/**
 * main - this is the entry point of this program
 * Return: this returns 0
 */
int main(void)
{
	char e;
	int a;
	long int b;
	long long int d;
	float f;

	printf("Size of a char: %lu byte(s)\n", sizeof(e));
	printf("Size of a int: %lu byte(s)\n", sizeof(a));
	printf("Size of a long int: %lu byte(s)\n", sizeof(b));
	printf("Size of a long long int: %lu byte(s)\n", sizeof(d));
	printf("Size of a float: %lu byte(s)\n", sizeof(f));
	return (0);
}
