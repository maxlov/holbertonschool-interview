#include <stdlib.h>
#include <stdio.h>
#include "holberton.h"

/**
 * wildcmp - Compares two strings. with a special char *
 *
 * @s1: The first string
 * @s2: The second string to compare to, may contain wildcard
 * Return: 1 if identical otherwise 0
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if (*s1 == *s2)
		return (wildcmp((s1 + 1), (s2 + 1)));
	if (*s2 == '*')
	{
		if (*s1 == '\0')
			return (wildcmp(s1, (s2 + 1)));
		return (wildcmp((s1 + 1), s2) || wildcmp(s1, (s2 + 1)));
	}
	return (0);
}
