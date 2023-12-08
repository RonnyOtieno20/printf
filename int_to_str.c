#include "main.h"

/**
 * int_to_string - Converts integer to string.
 * @num: Integer to convert into string
 * @buffer: A pointer to the buffer_t struct.
 *
 * Return: The number of characters written or -1 if error.
 */

int int_to_string(int num, buffer_t *buffer)
{

	int count = 0, i;
	int is_negative = 0;
	char digits[12];

	if (num == 0)
	{
		return (add_to_buffer(buffer, '0'));
	}

	if (num == INT_MIN)
	{

		if (add_to_buffer(buffer, '8') == -1)
			return (-1);
		num /= 10;
		num = -num;
		count++;
	}
	else if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	while (num != 0)
	{

		digits[count++] = (num % 10) + '0';
		num /= 10;
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
