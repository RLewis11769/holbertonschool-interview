# Integer Palindrome

Very simply check if a given positive integer is a palindrome. An integer palindrome is a number that is the same forward and reversed.

The "n" in question is an unsigned long int, which takes up 8 bytes of memory and consists of numbers from 0 to 18446744073709551615. No need for negative checks, but memory might be an issue.

The number to check will be passed in as argv[1] which will be passed to the program through the given main file as seen in the example section. All files will use the same main file which takes care of null checks, finds n, passes it to the task function, and prints based on function return. There is no need to mess with command line arguments or printing within the task function. The task requires a simple true/false in the form of returning 1 (true) for a palindrome or 0 if the number is not identical reversed.

## Example

After compiling as usual, test numbers for palindrome status using the command line:

```
./a.out 11
11 is a palindrome.
./a.out 112
112 is not a palindrome.
```

## Navigation

### palindrome.h
- Header file containing header guard and all prototypes used in answer file

### 0main.c
- Driver code for testing

### 0-palindrome.c
- Successful attempt!
- The logic is:
	- A palindrome is a number that is the same forward and reversed. So all I have to do is reverse a number and then check if reversed number is equal to the original.
	- There's one pretty standard way to reverse a number. I declare a variable "rev" to hold the memory. Then I loop through the original number to add the digits one at a time until I'm left with the reversed number in rev.
	- I've added a check for single-digit numbers because those are always palindromes. This is for memory reasons only and the function would work identically without it.
	- Very basic.
