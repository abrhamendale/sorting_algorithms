#include "sort.h"

/**
 * shell_sort - Sorts an array using shell sort algorithm
 *
 * @array: Array to be sorted
 * @size: The size of the array
 *
 */
void shell_sort(int *array, size_t size)
{
	unsigned int a = 1, span = 1, i = 0;
	int bspan = 1, tmp = 0, j = 0;

	while (a < size)
	{
		span = a;
		a = a * 3 + 1;
	}
	for (; span > 0 ; span = (span - 1) / 3)
	{
		for (i = 0 ; i < size - span ; i++)
		{
			if (array[i] > array[i + span])
			{
				tmp = array[i];
				array[i] = array[i + span];
				array[i + span] = tmp;
			}
			if (tmp)
			{
				bspan = i - span;
				j = i;
				while (bspan >= 0 && j >= 0)
				{
					if (array[j] < array[bspan])
					{
						tmp = array[j];
						array[j] = array[bspan];
						array[bspan] = tmp;
					}
					bspan -= span;
					j -= (int)span;
				}
				tmp = 0;
			}
		}
		print_array(array, size);
	}
}
