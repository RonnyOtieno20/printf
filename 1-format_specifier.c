#include "main.h"

/**
 * _print_bin - Prints the binary value.
 * @args: The arguments list.
 * @buffer: Pointer to the buffer_t struct.
 *
 * Return: The number of characters to be printed.
 */

int _print_bin(va_list args, buffer_t *buffer)
{

	unsigned int value = va_arg(args, unsigned int);

	return (unsigned_int_to_binary(value, buffer));
}

/**
 * _print_oct - Prints an octal number.
 * @args: The arguments list.
 * @buffer: Pointer to the buffer_t struct.
 *
 * Return: Number of characters printed.
 */

int _print_oct(va_list args, buffer_t *buffer)
{

	unsigned int n = va_arg(args, unsigned int);

	return (octal_to_str(n, buffer));
}

/**
 * _print_hex - Prints a hexadecimal number (lowercase).
 * @args: The arguments list.
 * @buffer: Pointer to the buffer_t struct.
 *
 * Return: Number of characters printed.
 */

int _print_hex(va_list args, buffer_t *buffer)
{

	unsigned int n = va_arg(args, unsigned int);

	return (hex_to_str(n, buffer, 0));
}

/**
 * _print_heX - Prints a hexadecimal number (uppercase).
 * @args: The arguments list.
 * @buffer: Pointer to the buffer_t struct.
 *
 * Return: Number of characters printed.
 */

int _print_heX(va_list args, buffer_t *buffer)
{

	unsigned int n = va_arg(args, unsigned int);

	return (hex_to_str(n, buffer, 1));
}
