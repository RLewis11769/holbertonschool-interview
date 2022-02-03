#include "slide_line.h"
#include <stdio.h>

/**
 * slide_line - Slides a line of integers to the left or right
 * @line: Pointer to the array of integers of size
 * @size: Number of elements in line
 * @direction: Direction to slide the line (either SLIDE_LEFT or SLIDE_RIGHT)
 * Return: 1 if successful, 0 if not
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t x, y;
	int array[size];

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	for (x = 0, y = 0; x < size; x++)
	{
		/* Skip 0s */
		if (!line[x])
			continue;
		/* Otherwise copy current source array into destination array */
		array[y++] = line[x];
	}

	/* Fill in remainder of array with zeros */
	for (; y < size; y++)
		array[y] = 0;

	if (direction == SLIDE_LEFT)
	{
		for (x = 0; x < size - 1; x++)
		{
			if (array[x] == array[x + 1])
				left_shift(array, size, x);
		}
	}

	/* Copy array back into orig array */
	for (x = 0; x < size; x++)
		line[x] = array[x];
	return (1);
}

/**
 * left_shift - Shifts an array to the left by one
 * @line: Pointer to the array to shift
 * @size: Number of elements in array
 * @x: Index of the element to shift
 */
void left_shift(int *line, size_t size, size_t x)
{
	/* Double value of current element */
	line[x] *= 2;
	/* Shift all other elements to the left */
	for (x = x + 1; x < size - 1; x++)
		line[x] = line[x + 1];
	line[size - 1] = 0;
}
