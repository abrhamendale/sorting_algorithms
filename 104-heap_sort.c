#include "sort.h"

void swapper(int *array, unsigned int i1, unsigned int i2)
{
	int tmp;

	printf("--------------swapper-------------\n");
	tmp = array[i1];	
	array[i1] = array[i2];
	array[i2] = tmp;
	print_array(array, 10);
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

	printf("--------------heap_sort-------------\n");
	for (i = 0 ; i < size ; i++)
	{
	/*
		if (i + 1 == (2 * p) || i == 1)
		{
			j = 1;
			sarray[i] = j;
			if (i != 1)
				p = i + 1;
			printf("\n");
		}
		else
			sarray[i] = j;
		printf("%d", array[i]);
	}
	printf("\n");
	*/
		sorter(array, 1, size - 1 - i);
		if (array[0] < array[1] && array[2] < array[1])
			swapper(array, 0, 1);
		if (array[0] < array[2] && array[1] < array[2])
			swapper(array, 0, 2);
		sorter(array, 2, size - 1 - i);
		swapper(array, 0, size - 1 - i);
	}
}
void sorter(int *array, int i, int end)
{
	printf("--------------sorter-------------\n");

	if (i + i + 1 <= end)
		sorter(array, i + i + 1, end);
	if (array[i] < array[i + i + 1] && array[i + i + 2] < array[i + i + 1] && i + i + 1 <= end)
		swapper(array, i, i + i + 1);
	/*if (i >= 0)
		sorter(array, i, end);*/
	if (i + i + 2 <= end)
	{
		sorter(array, i + i + 2, end);
		printf("111\n");
	}
	printf("222%d %d\n", i + i + 2, end);
	if (array[i] < array[i + i + 2] && array[i + i + 1] < array[i + i + 2] && i + i + 2 <= end)
		swapper(array, i, i + i + 2);
	/*if (i >= 0)
		sorter(array, i, end);*/
}
