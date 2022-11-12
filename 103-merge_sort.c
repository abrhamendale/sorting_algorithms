#include "sort.h"

/**
 * swapper - Swappes two elements of an array
 *
 * @array: Input array
 * @i1: First index
 * @i2:Second index
 *
 * Return: Nothing
 */
void swapper(int *array, unsigned int i1, unsigned int i2)
{
	int tmp;

	/*printf("--------------swapper-------------\n");*/
	tmp = array[i1];
	array[i1] = array[i2];
	array[i2] = tmp;
	/*print_array(array, 10);*/
}
/**
 * print_array_section - Prints an array of integers
 *
 * @array: The array to be printed
 * @start: Starting index
 * @end: End index
 *
 * Return: Nothing
 */
void print_array_section(const int *array,
		unsigned int start, unsigned int end)
{
	size_t i;

	i = start;
	while (array && i <= end)
	{
		if (i > start)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}
/**
 * merge_sort - Sorts an array using bubble sort algorithm
 *
 * @array: Array to be sorted
 * @size: The size of the array
 *
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	unsigned int i, j, k, l, m, r;

	/*printf("--------------merge_sort-------------\n");*/
	l = 0;
	r = size - 1;
	if ((r - l + 1) % 2 != 0)
		m = l - 1 + (r - l) / 2;
	else
		m = l + (r - l) / 2;
	/*printf("Left:%u Middle:%u Right:%u\n", l, m, r);*/
	if (r > l)
	{
		mergesorter(array, size, l, m);
		mergesorter(array, size, m + 1, r);
		printf("Merging...\n");
		printf("[left]: ");
		print_array_section(array, l, m);
		printf("[right]: ");
		print_array_section(array, m + 1, r);
		for (i = m + 1 ; i <= r ; i++)
		{
			k = i;
			for (j = i ; j >= l ; j--)
			{
				if (array[i] <= array[j])
				{
					swapper(array, i, j);
					i = j;
				}
				if (j == 0)
					break;
			}
			i = k;
		}
	}
	printf("[Done]: ");
	print_array_section(array, l, r);
}
/**
 * mergesorter - Sorts an array using merge sort algotirhm
 *
 * @array: Input array
 * @size: Size of the array
 * @l: Starting index
 * @r: End index
 *
 * Return: Nothing
 */
void mergesorter(int *array, size_t size, unsigned int l, unsigned int r)
{
	unsigned int m, i, j, k;

	/*printf("--------------mergesorter-------------\n");*/
	if (r > l)
	{
		if ((r - l + 1) % 2 != 0)
			m = l - 1 + (r - l) / 2;
		else
			m = l + (r - l) / 2;
		/*printf("Left:%u Middle:%u Right:%u\n", l, m, r);*/
		mergesorter(array, size, l, m);
		mergesorter(array, size, m + 1, r);
		printf("Merging...\n");
		printf("[left]: ");
		print_array_section(array, l, m);
		printf("[right]: ");
		print_array_section(array, m + 1, r);
		for (i = m + 1 ; i <= r ; i++)
		{/*printf("Inside outter for loop.Left:%u Middle:%u Right:%u\n", l, m, r);*/
			k = i;
			for (j = i ; j >= l ; j--)
			{/*printf("Inside inner for loop.%u %u\n", i, j);*/
				if (array[i] <= array[j])
				{
					swapper(array, i, j);
					i = j;
				}
				if (j == 0)
					break;
			}
			i = k;
		}
		printf("[Done]: ");
		print_array_section(array, l, r);
	}
	else
		return;
}
