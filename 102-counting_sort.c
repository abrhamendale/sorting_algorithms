#include "sort.h"

/**
 * counting_sort - Sorts an array using bubble sort algorithm
 *
 * @array: Array to be sorted
 * @size: The size of the array
 *
 */
void counting_sort(int *array, size_t size)
{
	unsigned int i;
	int max = 0, *carray;
	int *sarray = malloc (sizeof(int) * size);

	for (i = 0 ; i < size ; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	carray = malloc(sizeof(int) * (max + 1));
	for (i = 0 ; i < size ; i++)
		carray[array[i]]++;
	for (i = 1 ; i < (unsigned int)max + 1 ; i++)
		carray[i] = carray[i] + carray[i - 1];
	print_array(carray, max + 1);
	for (i = 0 ; i < size ; i++)
	{
		 sarray[carray[array[i]] - 1] = array[i];
		 carray[array[i]]--;
	}
	for (i = 0 ; i < size ; i++)
		array[i] = sarray[i];
	free(sarray);
	free(carray);
}
