#include "main.h"

/**
 * add_to_buffer - Adds a character to the buffer or flushes when full.
 * @buffer: Pointer to a buffer_t struct.
 * @c: Character to add to the buffer.
 *
 * Return: Nothing.
 */

int add_to_buffer(buffer_t *buffer, char c)
{

	if (!buffer || buffer->index >= BUFSIZE)
	{

		ssize_t written = write(1, buffer->buffer, buffer->index);

		buffer->index = 0;

		if (written < 0)
		{
			return (-1);
		}
	}
	buffer->buffer[buffer->index++] = c;

	return (0);
}
