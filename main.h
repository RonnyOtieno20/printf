#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>

#define BUFSIZE 1024

/**
 * struct buffer_s - Buffer structure
 * @buffer: Array of characters
 * @index: Position in the buffer
 */
typedef struct buffer_s
{

	char buffer[BUFSIZE];
	int index;
} buffer_t;

typedef int (*format_function)(va_list, buffer_t *buf);

/**
 * struct format_mapper - struct to map format specifiers to
 * their respective handler functions.
 * @specifier: first member.
 * @handler: second member.
 */
typedef struct format_mapper
{
	char specifier;
	format_function handler;
} format_mapper_t;

int _printf(const char *format, ...);
int _print_char(va_list args, buffer_t *buffer);
int _print_str(va_list args, buffer_t *buffer);
int _print_pct(va_list args, buffer_t *buffer);
int _print_int(va_list args, buffer_t *buffer);
int _print_bin(va_list args, buffer_t *buffer);
int int_to_string(int num, buffer_t *buffer);
int _print_u(va_list args, buffer_t *buffer);
int _print_oct(va_list args, buffer_t *buffer);
int _print_hex(va_list args, buffer_t *buffer);
int _print_heX(va_list args, buffer_t *buffer);
void init_format_handlers(format_mapper_t *format_mappers);
format_function fetch_handler
(format_mapper_t *format_mappers, char specifiers);
int unsigned_int_to_binary(unsigned int n, buffer_t *buffer);
int uint_to_str(unsigned int n, buffer_t *buffer);
int octal_to_str(unsigned int n, buffer_t *buffer);
int hex_to_str(unsigned int n, buffer_t *buffer, int uppercase);
int add_to_buffer(buffer_t *buffer, char c);
void handle_format(const char *format, int *i, va_list args, buffer_t *buffer,
		int *printed_chars, format_mapper_t *format_mappers);

#endif /* MAIN_H */
