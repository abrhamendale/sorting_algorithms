#include "sort.h"

/**
 * bubble_sort - Sorts an array using bubble sort algorithm
 *
 * @array: Array to be sorted
 * @size: The size of the array
 *
 */
void bitonic_sort(int *array, size_t size)
{
	bsorter(array, 0, size - 1);
}
void sequencer(int * array, unsigned int start, unsigned int end)
{
	sequencer(array, start, (end - start) / 2);
	bsorter(array, start, (end - start) / 2, 1);
	sequencer(array, (end - start) / 2, end);
	bsorter(array, (end - start) / 2, end, 0);
}

void bubblesort(int *array, unsigned int start, unisgned int end, int dir)
{
	unsigned int i, j;

        for (i = 0; i < size - 1; i++)
        {
                for (j = 0; j < size - 1; j++)
                {
			if (dir)
                        	if (array[j] > array[j + 1])
                        	{
                                	swap_elements(array, j);
                                	print_array(array, size);
                        	}
			else
                                if (array[j] < array[j + 1])
				{
					swap_elements(array, j);
					print_array(array, size);
				}
                }
        }
}
