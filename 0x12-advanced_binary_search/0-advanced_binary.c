#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"
#include <unistd.h>

/**
 * binary_helper - searches array with binary search algo
 * @array: list of integers being searched
 * @l: partition start
 * @r: partition end
 * @value: value being searched for
 * Return: index if succesful else -1
 */

int binary_helper(int *array, size_t l, size_t r, int value)
{
	size_t m;

	if (l >= r)
		return (-1);

	printf("Searching in array: ");
	for (m = l; m <= r; m++)
	{
		if (m != l)
			printf(", ");
		printf("%i", array[m]);
	}
	printf("\n");

	m = (l + r) / 2;

	sleep(1);
	if (array[m] == value && (r - l <= 1 || r == 0))
		return (m);
	if (array[m] >= value)
		return (binary_helper(array, l, m, value));
	else
		return (binary_helper(array, m + 1, r, value));
}

/**
 * advanced_binary - searches array with binary search algo
 * @array: list of integers being searched
 * @size: size of array
 * @value: value being searched for
 * Return: index if succesful else -1
 */

int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL)
		return (-1);
	return (binary_helper(array, 0, size - 1, value));
}
