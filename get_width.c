#include "main.h"
/**
 * get_print_func - finds the format function
 * @s: string
 * @ab: pointer
 * @params: the parameters struct
 * Return: bytes number
 */

int get_print_func(char *s, va_list ab, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(ab, params));
	return (0);
}

/**
 * get_flag - finds the flag functions
 * @s: the format of the string
 * @params:parameters struct
 * Return: if flag was valid
 */

int get_flag(char *s, params_t *params)

{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->plus_flag = 1;
			break;
		case ' ':
			i = params->space_flag = 1;
			break;
		case '#':
			i = params->hashtag_flag = 1;
			break;
		case '-':
			i = params->minus_flag = 1;
			break;
		case '0':
			i = params->zero_flag = 1;
			break;
	}
	return (i);
}

/**
 * get_modifier - gets the modifier
 * @s: string
 * @params: parameter struct
 * Return: if modifier was valid
 */

int get_modifier(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = params->h_modifier = 1;
			break;
		case 'l':
			i = params->l_modifier = 1;
			break;
	}
	return (i);
}

/**
 * get_width - gets the width
 * @s: string
 * @params:parameters struct
 * @ab: the argument pointer
 * Return: new pointer
 */

char *get_width(char *s, params_t *params, va_list ab)
{
	int d = 0;

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
	params->width = d;
	return (s);
}
