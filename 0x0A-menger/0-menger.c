#include "menger.h"

void menger(int level)
{
	if (level < 0)
		return;

	/* Size is 3^level - meaning 0 for 0, 3 for 1, 9 for 2, etc. */
	int size = pow(3, level);
	int r_check = 0, c_check = 0;
	int divisor, row, column, print;

	for (row = 0; row < size; row++)
	{
		for (column = 0; column < size; column++)
		{
			/* Default is to print */
			print = 1;
			/* Start by dividing row and column by 1 then 3, etc. */
			for (divisor = 1; divisor < size; divisor *= 3)
			{
				/* Check if row or column is divisible by divisor */
				r_check = ((row / divisor) % 3) == 1;
				c_check = ((column / divisor) % 3) == 1;
				/* If both are evenly divisible by divisor, print a space */
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