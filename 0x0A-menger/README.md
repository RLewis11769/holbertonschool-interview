# 2D Menger Sponge

## Description
We were given [this](https://www.youtube.com/watch?v=d-dI_pu_Z0g) video and [this](https://en.wikipedia.org/wiki/Menger_sponge) article for guidance with the instructions:

You will only draw a 2D version of the Menger sponge, but the principle is the same.
- A level 0 sponge is represented by the # character
- A level N sponge is a 3x3 square of level N-1 sponges, except for the center one, which is left empty

So:
- A level 0 sponge is a simple 1x1 square of the # characters
- A level 1 sponge is a 3x3 square of level 0 sponges, except for the center one, which is left empty
- A level 2 sponge is a 3x3 square of level 1 sponges, except for the center one, which is left empty

TIP: The size of a level N Menger sponge is calculated as follows: 3^N.

## Examples:

### Level 0 Menger sponge
\*

### Level 1 Menger sponge
\###
<br>
\#&nbsp; #
<br>
\###

### Level 2 Menger sponge
\#########
<br>
\#&nbsp; ## &nbsp;##&nbsp; #
<br>
\#########
<br>
\### &nbsp; &nbsp; &nbsp; ###
<br>
\#&nbsp; # &nbsp; &nbsp; &nbsp; #&nbsp; #
<br>
\### &nbsp; &nbsp; &nbsp; ###
<br>
\#########
<br>
\#&nbsp; ## &nbsp; ##&nbsp; #
<br>
\#########

## Logic

My initial approach was to find the index of each position that needed removed. In a level 1 sponge, index 4 was empty. In a level 2 sponge, 10, 13, and 16 were the first three indexes removed. All of these numbers stuck out to me as 3 + 1, or 3 * 3 + 1, etc. In the level 2, I noticed that 3^2 started the blanks, adding either 1, 4, or 7, which were significant for me as being 0 + 1, 3 + 1, and 6 + 1, or 3^0 + 1, 3^1 + 1, and 3^2 + 1. It continued at index 28, or 3^3 + 1.

None of this helped me find a solution, so I looked to the column numbers. In a level 2 sponge, the only rows that ever included blanks were 1, 3, 4, 5, and 7. Likewise for columns: 1, 3, 4, 5, and 7. The blanks in a level 2 sponge are: 1x1, 1x4, 1x7, 3x3, 3x4, 3x5, 4x1, 4x3, 4x4, 4x5, 4x7, 5x3, 5x4, 5x5, 7x1, 7x4, and 7x7.

This struck me as 1, 4, and 7 being the primary grouping, with 3, 4, and 5 as a secondary grouping for level 2. 4 % 3 is 1 and 7 % 3 is 1, so that's the first math I needed to do. If both row and column can be divided by 3^something, there's a blank.

I expected this logic to be the half of the solution, to be honest. When just this gave me the full solution, I had to look at it again. 3, 4, and 5 in a level 2 are always blank in every combination. In a level 3, it's row/column 9 - 17. That's 3^2 through 3^2 + 8, with 8 equating 3^2 - 1. As a reminder 3 - 5 are 3^1 through 3^1 + 2, where 2 is 3^1 - 1. There's some math in there that just worked out.

I'm not entirely sure why this solution works. I had an entire second portion of logic written out and was surprised when checking to see if the 1, 4, 7 logic worked. I suppose that's the entire point of a Menger sponge. In any case, printing as the default with flags to essentially check if grid[x][y] included 3^x, modulo or not, was my solution.

## Navigation

### menger.h
- Header file containing header guard and menger prototype used in answer file

### 0main.c
- Driver code for testing

### 0-menger.c
- Successful attempt!

