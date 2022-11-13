#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>
#include <ctype.h>
#include <limits.h>
#include <unistd.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;
/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void swap_elements(int *array, unsigned int index);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
listint_t *swap_list_elements(listint_t **list, listint_t *swp);
listint_t *create_listint(const int *array, size_t size);
size_t get_size(listint_t **list);
void partition_left(int *array, unsigned int start,
		unsigned int end, size_t size);
void swapper(int *array, unsigned int i1, unsigned int i2);
void sorter(int *array, int i, int end);
void mergesorter(int *array, size_t size, unsigned int l, unsigned int r);
void print_array_section(const int *array,
		unsigned int start, unsigned int end);
#endif
