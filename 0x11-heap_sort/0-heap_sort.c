#include "sort.h"

/**
 * heapify - turns a subtree into a heap at node i
 *
 * @array: array being sorted
 * @size: size of subtree
 * @i: node of root
 * @length: length of array
 */
void heapify(int array[], int size, int i, int length)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int temp;

	if (l < size && array[l] > array[largest])
		largest = l;

	if (r < size && array[r] > array[largest])
		largest = r;

	if (largest != i)
	{
		temp = array[largest];
		array[largest] = array[i];
		array[i] = temp;
		print_array(array, length);

		heapify(array, size, largest, length);
	}
}

/**
 * heap_sort - Sorts an array in ascending order using heap sort algorithm
 *
 * @array: array being sorted
 * @size: number being tested
 *
 */
void heap_sort(int *array, size_t size)
{
	int temp;
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);

		heapify(array, i, 0, size);
	}
}
