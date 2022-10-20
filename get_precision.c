#include "main.h"

/**
 * get_precision - finds the precision
 * @s: format string
 * @params: struct parameters
 * @ab: points to argument
 * Return: a pointer
 */

char *get_precision(char *s, params_t *params, va_list ab)
{
	int d = 0;

	if (*s != '.')
		return (s);
	s++;
	if (*s == '*')
	{
		d = va_arg(ab, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->precision = d;
	return (s);
}
