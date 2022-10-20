#include "main.h"

/**
 * print_char - prints character
 * @ab: argument pointer
 * @params: the parameters struct
 * Return: number chars printed
 */
int print_char(va_list ab, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(ab, int);

	if (params->minus_flag)
		sum += _putchar(ch);
	while (pad++ < params->width)
		sum += _putchar(pad_char);
	if (!params->minus_flag)
		sum += _putchar(ch);
	return (sum);
}

/**
 * print_int - prints integer
 * @ab: argument pointer
 * @params: the parameters struct
 * Return: number characters printed
 */
int print_int(va_list ab, params_t *params)
{
	long l;

	if (params->l_modifier)
		l = va_arg(ab, long);
	else if (params->h_modifier)
		l = (short int)va_arg(ab, int);
	else
		l = (int)va_arg(ab, int);
	return (print_number(convert(l, 10, 0, params), params));
}

/**
 * print_string - prints a string
 * @ab: pointer to the argument
 * @params: the parameters struct
 * Return: number characters printed
 */
int print_string(va_list ab, params_t *params)
{
	char *str = va_arg(ab, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)params;
	switch ((int)(!str))
	case 1:
		str = NULL_STRING;
		j = pad = _strlen(str);
		if (params->precision < pad)
			j = pad = params->precision;
		if (params->minus_flag)
		{
			if (params->precision != UINT_MAX)
				for (i = 0; i < pad; i++)
					sum += _putchar(*str++);
			else
				sum += _puts(str);
		}
		while (j++ < params->width)
			sum += _putchar(pad_char);
		if (!params->minus_flag)
		{
			if (params->precision != UINT_MAX)
				for (i = 0; i < pad; i++)
					sum += _putchar(*str++);
			else
				sum += _puts(str);
		}
		return (sum);
}

/**
 * print_percent - prints a string to stdout
 * @ab: pointer to argument
 * @params: the parameters struct
 * Return: number characters to be printed
 */
int print_percent(va_list ab, params_t *params)
{
	(void)ab;
	(void)params;
	return (_putchar('%'));
}

/**
 * print_S - format specifier
 * @ab: argument pointer
 * @params: the parameters struct
 * Return: number characters to printed
 */
int print_S(va_list ab, params_t *params)
{
	char *str = va_arg(ab, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}
