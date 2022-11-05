#include "sort.h"

/**
 * swap_elements - Swaps elements of an array
 *
 * @array: Input array
 * @index: Starting index
 *
 * Return: Nothing
 */
void swap_elements(int *array, unsigned int index)
{
	int tmp;

	tmp = array[index];
	array[index] = array[index + 1];
	array[index + 1] = tmp;
}
/**
 * bubble_sort - Sorts an array using bubble sort algorithm
 *
 * @array: Array to be sorted
 * @size: The size of the array
 *
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, j;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_elements(array, j);
				print_array(array, size);
			}
		}
	}
}
