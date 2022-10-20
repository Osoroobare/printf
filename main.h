#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define FIELD_BUF_SIZE 50

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct params - struct parameters
 * @unsign: unsigned value
 * @plus_flag: when plus_flag is defined
 * @space_flag: when hashtag_flag defined
 * @hashtag_flag: when _flag defined
 * @zero_flag: when_flag defined
 * @minus_flag: when_flag defined
 * @width: width defined
 * @precision: precision defined
 * @h_modifier: when h_modifier is defined
 * @l_modifier: when l_modifier is defined
 */

typedef struct params
{
	unsigned int unsign		: 1;
	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;
	unsigned int width;
	unsigned int precision;
	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} params_t;

/**
 * struct specifier - Struct token
 * @specifier: format token
 * @f: The function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;
/*write_functions*/
int _puts(char *str);
int _putchar(int c);
/*numbers.c functions*/
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ab, params_t *params);
int print_address(va_list ab, params_t *params);
/*specifier_functions */
int (*get_specifier(char *s))(va_list ab, params_t *params);
int get_print_func(char *s, va_list ab, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ab);
/* converts_number.c functions */
int print_hex(va_list ab, params_t *params);
int print_HEX(va_list ab, params_t *params);
int print_binary(va_list ab, params_t *params);
int print_octal(va_list ab, params_t *params);
/*print_numbers.c*/
int print_string(va_list ab, params_t *params);
int print_percent(va_list ab, params_t *params);
int print_S(va_list ab, params_t *params);
int print_char(va_list ab, params_t *params);
int print_int(va_list ab, params_t *params);
/* simple_printers.c functions */
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ab, params_t *params);
int print_rot13(va_list ab, params_t *params);
/* print_number.c functions */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);
/* params.c functions */
void init_params(params_t *params, va_list ab);
/* string_fields.c functions */
char *get_precision(char *p, params_t *params, va_list ab);
/* _prinf.c functons */
int _printf(const char *format, ...);
/*get_print*/
int (*get_print(char s))(va_list, params_t *);

#endif /*MAIN_H*/
