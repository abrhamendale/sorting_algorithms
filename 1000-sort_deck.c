#include "sort.h"

/**
 * swapper - Swaps array elements
 *
 * @array: Input array
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
 * quick_sort - Sorts an array using bubble sort algorithm
 *
 * @array: Array to be sorted
 * @size: The size of the array
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	int pivot;
	unsigned int i, start = 0, end = size - 1, s = -1;

	/*printf("---------quick_sort---------\n");*/
	pivot = array[size - 1];
	for (i = 0; i < size; i++)
	{
		if (array[i] < pivot)
		{
			s++;
			swapper(array, i, s);
			if (array[i] != array[s])
				print_array(array, size);
		}
		if (i == size - 2)
		{
			swapper(array, size - 1, s + 1);
			if (array[size - 1] != array[s + 1])
				print_array(array, size);
		}
	}
	if (s + 1 != 0)
		partition_left(array, start, s, size);
	partition_left(array, s + 2, end, size);
}
/**
 * partition_left - partitions the array
 *
 * @array: Input array
 * @start: Start of the partition
 * @end: The end of the partition
 * @size: The end of the partiotn
 *
 * Return: Nothing
 */
void partition_left(int *array, unsigned int start, unsigned
		int end, size_t size)
{
	int pivot;
	unsigned int i, s = -1;

	pivot = array[end];

	if (start == end)
		return;
	for (i = start; i < end; i++)
	{
		if (array[i] < pivot)
		{
			s++;
			swapper(array, i, start + s);
			if (array[i] != array[start + s])
				print_array(array, size);
		}
		if (i == end - 1)
		{
			swapper(array, end, start + s + 1);
			if (array[end] != array[start + s + 1])
				print_array(array, size);
		}
	}
	if (s + 1 > 0)
		partition_left(array, start, start + s, size);
	if (start + s + 1 < end)
		partition_left(array, start + s + 2, end, size);
}
