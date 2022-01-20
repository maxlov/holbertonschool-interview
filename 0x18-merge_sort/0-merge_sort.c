#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * print_specific_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @start: Where to start printing
 * @end: End of print
 */
void print_specific_array(const int *array, size_t start, size_t end)
{
	size_t original_start = start;

	while (array && start < end)
	{
		if (start > original_start)
			printf(", ");
		printf("%d", array[start]);
		++start;
	}
	printf("\n");
}

/**
 * merge_halves - Merges two sub arrays together
 *
 * @array: The array to be sorted
 * @l: Start of array
 * @m: Middle of array
 * @r: End of array
 */
void merge_halves(int *array, int l, int m, int r)
{
	int i_left, i_right, i_merged;

	int sub_left_size = m - l + 1;
	int sub_right_size = r - m;

	int left_temp[500];
	int right_temp[500];

	for (i_left = 0; i_left < sub_left_size; i_left++)
		left_temp[i_left] = array[l + i_left];
	for (i_right = 0; i_right < sub_right_size; i_right++)
		right_temp[i_right] = array[m + 1 + i_right];

	i_left = 0;
	i_right = 0;
	i_merged = l;

	while (i_left < sub_left_size && i_right < sub_right_size)
	{
		if (left_temp[i_left] <= right_temp[i_right])
		{
			array[i_merged] = left_temp[i_left];
			i_left++;
		}
		else
		{
			array[i_merged] = right_temp[i_right];
			i_right++;
		}
		i_merged++;
	}

	for (; i_left < sub_left_size; i_left++, i_merged++)
		array[i_merged] = left_temp[i_left];
	for (; i_right < sub_right_size; i_right++, i_merged++)
		array[i_merged] = right_temp[i_right];
}

/**
 * merge_sort_recur - Recursive function to sort array
 *
 * @array: The array to be sorted
 * @l: Start of array
 * @r: End of array
 */
void merge_sort_recur(int *array, int l, int r)
{
	int m;

	if (l < r)
	{
		m = l + (r - l) / 2;

		merge_sort_recur(array, l, m);
		merge_sort_recur(array, m + 1, r);

		printf("Merging...\n");
		printf("[left]: ");
		print_specific_array(array, 0, m + 1);

		printf("[right]: ");
		print_specific_array(array, m + 1, r + 1);

		merge_halves(array, l, m, r);
		printf("[Done]: ");
		print_array(array, r + 1);
	}
}

/**
 * merge_sort - Sorts an array using top down merge sort
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
	merge_sort_recur(array, 0, size - 1);
}
