#include "main.h"

/**
 * print_from_to - prints a range charaters
 * @start: adress to start from
 * @stop: address to stop
 * @except: address to ommit
 * Return: number bytes printed
 */
int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
 * print_rev - reverses a string
 * @ab: the string to be reversed
 * @params: the parameters structure
 * Return: number bytes printed
 */
int print_rev(va_list ab, params_t *params)
{
	int len, sum = 0;
	char *str = va_arg(ab, char *);
	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/**
 * print_rot13 - prints string in rot13
 * @ab: string to be reversed
 * @params: the parameters structure
 * Return: number bytes printed
 */
int print_rot13(va_list ab, params_t *params)
{
	int i, index;
	int count = 0;
	char arr[] = "NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ab, char *);
	(void)params;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z')
				|| (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}
