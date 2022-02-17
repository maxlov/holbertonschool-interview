#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * radix_sort - LSD radix sort
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void radix_sort(int *array, size_t size)
{
	int i = 0;
	int maximum;
	int place_digit;
	int place = 1;
	int *sort_step;
	int digit_count[10];

	if (array == NULL || size < 2)
		return;

	maximum = array[0];
	for (i = 1; i < (int)size; i++)
		if (maximum < array[i])
			maximum = array[i];

	for (; maximum / place > 0; place *= 10)
	{
		sort_step = malloc(sizeof(int) * size);
		for (i = 0; i < 10; i++)
			digit_count[i] = 0;
		for (i = 0; i < (int)size; i++)
			digit_count[(array[i] / place) % 10]++;
		for (i = 1; i < 10; i++)
			digit_count[i] += digit_count[i - 1];
		for (i = (int)size - 1; i >= 0; i--)
		{
			place_digit = (array[i] / place) % 10;
			sort_step[digit_count[place_digit] - 1] = array[i];
			digit_count[place_digit]--;
		}

		for (i = 0; i < (int)size; i++)
			array[i] = sort_step[i];
		free(sort_step);
		print_array(array, size);
	}
}
