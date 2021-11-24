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

### Navigation

### 0main.py
- Driver code for testing
- Last test (1000 boxes with all keys in each box) fails recursive and loop attempts due to memory issues

### 0-minoperations.py
- Successful attempt!
- Based off the wonderful, amazing [Brian Kong](https://github.com/rkbrian) and his incredible math who posted:
	- My logic for minimum operation: loop (copy_all + paste + paste + paste + ...paste n times) = amount + amount + ...= amount * (n + 1); loop (copy_all + paste + copy_all + paste + ...(copy_all + paste) n times) = amount * amount * ... = amount ^ (n + 1). The latter saves moves. If you use the loops properly, this problem will became prime factorization, e.g., input = 120 = 2x2x2x3x5, total min ops = 2+2+2+3+5 = 14
	- SO prime factorization:
		- Start dividing n from smallest prime number aka 2
		- If divisible by 2 but not a prime number, divide again
		- If not divisible by 2, try 3, 5, 7, etc.
		- When all factors are prime numbers, have found answer
			- Examples:
				- 12 = 2 * 2 * 3
				- 147 = 3 * 7 * 7
				- 17 = 17
		- As Brian mentioned, adding the factors will get the number of minimum operations

### just_math.py
- Another successful attempt!
- Also based off of Brian's prime factorization logic
- Increase copyall by one every loop and paste by the last prime number you checked - 1
	- Basically just get the number of times each is done/factorized rather than adding the factors

### loop.py
- Failed attempt
- Based off of my logic
	- Final else loop is too simplified when loop multiple times but would require a convoluted loop to fix
