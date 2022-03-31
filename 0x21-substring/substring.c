#include <stdlib.h>
#include <stdio.h>

#include "substring.h"

/**
 * find_substring - Entry point
 * @s: is the string to scan
 * @words: the array of words all substrings must be a concatenation of
 * @nb_words: the number of elements in the array words
 * @n: holds address  to store the number of elements in the returned array.
 * Return: Allocated array of each index of substrings found. NULL if none
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	(void)s, (void)words, (void)nb_words;
	*n = 0;
	return (NULL);
}
