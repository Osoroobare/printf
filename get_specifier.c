#include "main.h"

/**
 * get_specifier - picks a formating function
 * @s: format string
 * Return: number of characters printed
 */

int (*get_specifier(char *s))(va_list ab, params_t *params)

{
	specifier_t specifiers[] = {
		{"d", print_int},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"c", print_char},
		{"i", print_int},
		{"s", print_string},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);
}
