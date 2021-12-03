#include "sandpiles.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * sandpiles_sum - sums two sandpiles and topples until sum is stable
 * @grid1: first 3x3 grid of integers to sum, assumed to be stable
 * @grid2: second 3x3 grid of integers to sum, assumed to be stable
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int row, col;
	int flags[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	/* sum grid1 and grid2 into grid1 */
	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
			grid1[row][col] = grid1[row][col] + grid2[row][col];
	}

	while (unstable_grid(grid1, flags))
	{
		/* print unstable grid before toppling */
		printf("=\n");
		print_grid(grid1);
		/* for every indicated flag, topple cell */
		for (row = 0; row < 3; row++)
		{
			for (col = 0; col < 3; col++)
			{
				if (flags[row][col])
					topple(grid1, row, col);
			}
		}
	}
}

/**
 * unstable_grid - checks stability of grid1 and sets flags where unstable
 * @grid1: 3x3 grid of integers to check stability of
 * @flags: 3x3 gird indicating where unstable cells are prior to toppling
 * Return: 1 if unstable, 0 if doesn't need to topple
 */
int unstable_grid(int grid1[3][3], int flags[3][3])
{
	int check = 0;
	int row, col;

	for (row = 0; row < 3; row++)
	{
		for (col = 0; col < 3; col++)
		{
			if (grid1[row][col] > 3)
			{
				check = 1;
				flags[row][col] = 1;
			}
			else
				flags[row][col] = 0;
		}
	}
	return (check);
}

/**
 * topple - topples individual cell
 * @grid1: 3x3 grid that holds cell to topple
 * @row: row of cell to topple
 * @col: column of cell to topple
 */
void topple(int grid1[3][3], int row, int col)
{
	grid1[row][col] -= 4;
	if (row - 1 >= 0)
		grid1[row - 1][col] += 1;
	if (row + 1 < 3)
		grid1[row + 1][col] += 1;
	if (col - 1 >= 0)
		grid1[row][col - 1] += 1;
	if (col + 1 < 3)
		grid1[row][col + 1] += 1;
}
