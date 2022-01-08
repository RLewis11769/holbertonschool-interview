# Sandpiles

## Description

We were given [this video](https://www.youtube.com/watch?v=1MtEUErz7Gg) for guidance with the instructions:
- You can assume that both grid1 and grid2 are individually stable
- A sandpile is considered stable when none of its cells contains more than 3 grains
- When your function is done, grid1 must be stable
- grid1 must be printed before each toppling round, only if it is unstable (See example)
- You're not allowed to allocate memory dynamically

## Example

int grid1[3][3] = {\
  {3, 3, 3},\
  {3, 3, 3},\
  {3, 3, 3}\
};

int grid2[3][3] = {\
  {1, 3, 1},\
  {3, 3, 3},\
  {1, 3, 1}\
};

returns the result:

<pre>
3 3 3   1 3 1
3 3 3 + 3 3 3
3 3 3   1 3 1
=
4 6 4
6 6 6
4 6 4
=
2 5 2
5 6 5
2 5 2
=
4 2 4
2 6 2
4 2 4
=
0 5 0
5 2 5
0 5 0
=
2 1 2
1 6 1
2 1 2
=
2 2 2
2 2 2
2 2 2
</pre>

If a cell is unstable, it needs to be toppled. As you loop through each cell, if a number is 4 or above, subtract 4 from it. Then, if the surrounding cells exist, add 1 to each of them.

While cycling through row then col, the cell above is grid[row - 1][col], below is grid[row + 1][col], left is grid1[row][col - 1], and right is grid1[row][col + 1].

A note I made but was unable to implement is that a stable grid consists of only 3 numbers:\
[A, B, A]\
[B, C, B]\
[A, B, A]

While working through sandpiles myself, I found that simply finding the results for A, B, and C was the easiest way to find the solution. However, while finding the number would be fairly simple, poulating each cell with the calculated number would likely require additional functions with hardcoded information about what grid[1][2] would do when grid[1][1] was unstable etc. I didn't find this very efficient for me to do so didn't implement it.

However, I'm now considering that the Big O of the current solution is O(n<sup>2</sup>) because of all of the nested loops. A hardcoded solution with like 6 functions would probably be more memory efficient. Too bad these tasks are pass/fail with no bonus for memory efficiency.

I would also like to note that if given UNstable grids to add, the most efficient solution would likely involve something like `if (n % 4)` to take advantage of the fact that the unstable cell would need to be divided by a number and the surrounding cells would need to increase by the same number.

Note that the two sandpiles must be added, then printed. The printing function as seen in 0-sandpiles.c was provided to us.

## Navigation

### sandpiles.h
- Header file containing header guard and all prototypes used in answer file

### 0main.c
- Driver code for testing

### 0-sandpiles.c
- Successful attempt!
- Printing was the tricky part. After many hours, I landed on adding a matrix consisting only of a yes/no on whether or not a grid was stable. At that point, I could print the combined grid, then topple cells if necessary.
