#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"

/**
 * is_palindrome - Determines if unsigned long int is a palindrome or not
 *
 * @n: number being tested
 *
 * Return: 1 if palindrome else 0
 */
int is_palindrome(unsigned long n)
{
	unsigned long size = 10;
	unsigned long left;

	while ((n / size) >= 10)
		size *= 10;

	while (n > 0)
	{
		left = n / size;

		if (left != n % 10)
			return (0);

		n -= left * size;
		n /= 10;
		size /= 100;
	}
	return (1);
}
