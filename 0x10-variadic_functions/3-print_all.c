#include <stdio.h>
#include <stdarg.h>
/**
  * print_all - prints anything.
  * @format: list of types of arguments passed to the function
  *
  * Return: Nothing
  */
void print_all(const char * const format, ...)
{
	int j, i = 0;
	char *str;
	va_list list;

	va_start(list, format);

	while (format[i] != '\0')
	{
		j = 0;

		switch (format[i])
		{
			case 'c':
				j = printf("%c", va_arg(list, int));
				break;

			case 'i':
				j = printf("%d", va_arg(list, int));
				break;

			case 'f':
				j = printf("%f", va_arg(list, double));
				break;

			case 's':
				str = va_arg(list, char *);

				if (str == NULL)
					str = "(nil)";

				j = printf("%s", str);
		}

		if (j != 0 && format[i + 1] != '\0')
			printf(", ");
		i++;
	}

	va_end(list);
	printf("\n");
}
