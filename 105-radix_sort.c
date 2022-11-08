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
 * radix_sort - Sorts an array using bubble sort algorithm
 *
 * @array: Array to be sorted
 * @size: The size of the array
 *
 * Return: Nothing
 */
void radix_sort(int *array, size_t size)
{
	unsigned int i, j, k, count = 0, rem1, rem2;
	int max = 0, *sarray;

	sarray = malloc(sizeof(int) * size);
	memcpy(sarray, array, size * sizeof(int));
	for (i = 0 ; i < size - 1 ; i++)
		if (array[i] > max)
			max = array[i];
	while (max)
	{
		max = max / 10;
		count++;
	}
	for (k = 1 ; k <= count ; k++)
	{
		for (i = 0; i < size - 1; i++)
		{
			for (j = 0; j < size - 1; j++)
			{
				rem1 = sarray[j] % (10);
				rem2 = sarray[j + 1] % (10);
				if (rem1 > rem2)
				{
					swap_elements(array, j);
					swap_elements(sarray, j);
				}
			}
		}
		for (j = 0 ; j < size ; j++)
			sarray[j] /= 10;
		print_array(array, size);
	}
}
