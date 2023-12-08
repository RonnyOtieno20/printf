#include "main.h"

/**
 * int_to_string - Converts integer to string.
 * @n: Integer to convert into string
 * @buffer: A pointer to the buffer_t struct.
 *
 * Return: The number of characters written or -1 if error.
 */

int int_to_string(int n, buffer_t *buffer)
{

	int count = 0, i;
	int is_negative = 0;
	char digits[12];

	if (n == 0)
	{
		return (add_to_buffer(buffer, '0'));
	}

	if (n == INT_MIN)
	{

		if (add_to_buffer(buffer, '8') == -1)
			return (-1);
		n /= 10;
		n = -n;
		count++;
	}
	else if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	while (n != 0)
	{

		digits[count++] = (n % 10) + '0';
		n /= 10;
	}
	if (is_negative)
		digits[count++] = '-';

	for (i = count - 1; i >= 0; i--)
	{
		if (add_to_buffer(buffer, digits[i]) == -1)
			return (-1);
	}

	return (count);
}
