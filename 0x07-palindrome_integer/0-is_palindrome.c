#include "palindrome.h"
#include <stdio.h>
/**
 * is_palindrome - check if given number is palindrome
 * @n: number to check
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(unsigned long n)
{
	unsigned long rev = 0;
	unsigned long temp = n;

	if (n < 10)
		return (1);

	/* Reverse number */
	while (temp)
	{
		/* Start with holding last digit, then add each digit as removed*/
		rev = (rev * 10) + (temp % 10);
		/* Remove last digit */
		temp /= 10;
	}

	/* Compare original and reversed number */
	if (n == rev)
		return (1);

	return (0);
}
