# Minimum Operations

## Description

In a text file, there is a single character 'H'. Your text editor can execute only two operations in this file: "Copy All" and "Paste". "Copy All" copies the existing string. "Paste" adds the string in the clipboard to the file.

Given a number n, write a method that calculates the fewest number of operations needed to result in exactly n 'H' characters in the file.

Returns an integer.

If n is impossible to achieve, return 0.

## Example

#### Input: n = 9
- Output: 6
- Explanation:
H => Copy All (1) => Paste (2) => HH => Paste (3) => HHH => Copy All (4) => Paste (5) => HHHHHH => Paste (6) => HHHHHHHHH
