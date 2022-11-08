#include "sort.h"

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
	unsigned int i, start = 0, end = size - 1;
	unsigned int left = 0, right = 1;
	int *tarray = malloc(sizeof(int) * size);

	memcpy(tarray, array, size * sizeof(int));
	/*printf("---------quick_sort---------\n");*/
	pivot = array[size - 1];
	for (i = 0; i < size; i++)
	{
		if (array[i] < pivot)
		{
			tarray[left] = array[i];
			/*printf("%d", tarray[left]);*/
			left++;
		}
		if (array[i] > pivot)
		{
			tarray[size - right] = array[i];
			/*printf("\t");
			 *printf("%d %d", tarray[size - right], array[i]);
			 */
			right++;
		}
	}
	tarray[left] = pivot;
	/*printf("\n");
	 *print_array(tarray, end - start + 1);
	 *printf("start:%d end:%d\n", start, end);
	 */
	print_array(tarray, end - start + 1);
	if (left != 0)
        	partition_left(tarray, start, left - 1, size);
	partition_left(tarray, left + 1, end, size);
	memcpy(array, tarray, size * sizeof(int));
	free(tarray);
}
void partition_left(int *array, unsigned int start, unsigned int end, size_t size)
{
	int pivot;
        unsigned int i, left = 0, right = 0;
	int *tarray = malloc(sizeof(int) * size);

	pivot = array[end];
	memcpy(tarray, array, size * sizeof(int));
	/*
	 * printf("---------partition_left---------\n");
	 * printf("start:%d end:%d pivot:%d\n", start, end, pivot);
	*/
	if (start == end)
		return;
	for (i = start; i < end; i++)
        {
		if (array[i] < pivot)
                {
			tarray[start + left] = array[i];
			left++;
		}
		if (array[i] > pivot)
		{
			tarray[end - right] = array[i];
			right++;
		}
	}
	tarray[start + left] = pivot;
	print_array(tarray, 10);
	if (left > 0)
		partition_left(tarray, start, start + left - 1, size);
	if (start + left < end)
		partition_left(tarray, start + left + 1, end, size);
	free(tarray);
}
