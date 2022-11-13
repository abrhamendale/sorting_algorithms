#include "sort.h"

/**
 * swapper - Swaps two elements of an array
 *
 * @array: Iput array
 * @i1: Index 1
 * @i2: Index 2
 *
 * Return: Nothing
 */
void swapper(int *array, unsigned int i1, unsigned int i2)
{
	int tmp;

	tmp = array[i1];
	array[i1] = array[i2];
	array[i2] = tmp;
}
/**
 * heap_sort - Sorts an array using bubble sort algorithm
 *
 * @array: Array to be sorted
 * @size: The size of the array
 *
 */
void heap_sort(int *array, size_t size)
{
	unsigned int i;

	for (i = 0 ; i < size ; i++)
	{
		sorter(array, 1, size - 1 - i);
		if (array[0] < array[1] && array[2] < array[1] && size - 1 - i >= 2)
		{
			swapper(array, 0, 1);
			print_array(array, size);
			sorter(array, 1, size - 1 - i);
		}
		if (array[0] < array[2] && array[1] < array[2] && size - 1 - i >= 2)
		{
			swapper(array, 0, 2);
			print_array(array, size);
			sorter(array, 2, size - 1 - i);
		}
		if (size - 1 - i >= 2)
			sorter(array, 2, size - 1 - i);
		if (size - 1 - i == 1 && array[0] < array[1])
		{
			swapper(array, 0, size - 1 - i);
			print_array(array, size);
		}
		if (size - 1 - i > 0)
		{
			swapper(array, 0, size - 1 - i);
			print_array(array, size);
		}
	}
}
/**
 * sorter - Sortes sections of the max heap
 *
 * @array: Input array
 * @i:Index of heap
 * @end: End of array
 *
 * Return: Nothing
 */
void sorter(int *array, int i, int end, size_t size)
{
	if (i == end)
		return;
	if (i + i + 1 <= end)
	{
		sorter(array, i + i + 1, end);
	}
	if (array[i] < array[i + i + 1] && (i + i + 2 > end ||
				array[i + i + 2] < array[i + i + 1]) && i + i + 1 <= end)
	{
		swapper(array, i, i + i + 1);
		print_array(array, size);
		sorter(array, i + i + 1, end);
	}
	if (i + i + 2 <= end)
	{
		sorter(array, i + i + 2, end);
	}
	if (array[i] < array[i + i + 2] && array[i + i + 1]
			< array[i + i + 2] && i + i + 2 <= end)
	{
		swapper(array, i, i + i + 2);
		print_array(array, size);
		sorter(array, i + i + 2, end);
	}
}
