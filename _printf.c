#include "main.h"

/**
 * _printf - prints output according to a given format
 * @format: the character string to be printed
 * Return: number of characters printed
 */

int _printf(const char *format, ...)

{
	int sum = 0;

	va_list ab;
	char *p, *start;
	params_t params = PARAMS_INIT;

	va_start(ab, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, ab);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &params))
		{
			p++;
		}
		p = get_width(p, &params, ab);
		p = get_precision(p, &params, ab);
		if (get_modifier(p, &params))
			p++;
		if (!get_specifier(p))
			sum += print_from_to(start, p,
					params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			sum += get_print_func(p, ab, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(ab);
	return (sum);
}
