#ifndef SANDPILES_H
#define SANDPILES_H

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
int unstable_grid(int grid1[3][3], int flags[3][3]);
void topple(int grid1[3][3], int row, int col);
void print_grid(int grid[3][3]);

#endif
