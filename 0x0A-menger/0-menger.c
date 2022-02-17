#include "menger.h"

/**
 * menger - prints a 2D menger sponge
 * @level: level of the menger sponge
 */
void menger(int level)
{
	/* Size is 3^level - meaning 0 for 0, 3 for 1, 9 for 2, etc. */
	int size = pow(3, level);
	int divisor, row, column, r_check, c_check, print;

	if (level < 0)
		return;

	for (row = 0; row < size; row++)
	{
		for (column = 0; column < size; column++)
		{
			/* Default is to print */
			print = 1;
			/* Start by dividing row and column by 1 then 3, etc. */
			for (divisor = 1; divisor < size; divisor *= 3)
			{
				/* Check if row or column is divisible by divisor with remainder of 1*/
				r_check = ((row / divisor) % 3) == 1;
				c_check = ((column / divisor) % 3) == 1;
				/* If both have remainder of 1, print a space */
				if (r_check && c_check)
					print = 0;
			}
			if (print)
				putchar('#');
			else
				putchar(' ');
		}
		putchar('\n');
	}
}
