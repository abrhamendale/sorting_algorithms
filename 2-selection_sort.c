#include "sort.h"

/**
 * selection_sort - Sorts an array using bubble sort algorithm
 *
 * @array: Array to be sorted
 * @size: The size of the array
 *
 * Return: Nothing
 *
 */
void selection_sort(int *array, size_t size)
{
        unsigned int i, j;
        int tmp, min , jmin = 0;

        if (size == 0)
                return;
        for (i = 0; i < size; i++)
        {
                min = array[i];
                for (j = i + 1; j < size; j++)
                {
                        if (array[j] < min)
			{
                                min = array[j];
				jmin = j;
			}
                }
		tmp = array[i];
                array[i] = min;
                array[jmin] = tmp;
		if (array[i] != array[jmin])
			print_array(array, size);
        }
}
