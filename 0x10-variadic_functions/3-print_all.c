#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * p_char - print char
 * @all: va list
 */

void p_char(va_list all)
{
	printf("%c", va_arg(all, int));
}

/**
 * p_integer - print integer
 * @all : va list
 */

void p_integer(va_list all)
{
	printf("%d", va_arg(all, int));
}

/**
 * p_float - print float
 * @all : va list
 */

void p_float(va_list all)
{
	printf("%f", va_arg(all, double));
}

/**
 * p_string - print strings
 * @all : va list
 */

void p_string(va_list all)
{
	char *string;

	string = va_arg(all, char *);

	if (string == NULL)
	{
		printf("(nil)");
		return;
	}
	printf("%s", string);
}

/**
 * print_all - prints anything
 * @format: a list of types of arguments passed to the function
 * @...: parameters
 */

void print_all(const char * const format, ...)
{
	int i, j;
	char *sep = "";
	va_list all;

	choice symbol[] = {
		{'c', p_char},
		{'i', p_integer},
		{'f', p_float},
		{'s', p_string},
		{'\0', NULL}
	};

	va_start(all, format);

	j = 0;

	while (format != NULL && format[j] != '\0')
	{
		i = 0;

		while (symbol[i].letter != '\0')
		{
			if (symbol[i].letter == format[j])
			{
				printf("%s", sep);
				symbol[i].print(all);
				sep = ", ";
			}
			i++;
		}
		j++;
	}
	va_end(all);
	printf("\n");
}
