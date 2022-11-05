#include "sort.h"

/**
 * swap_list_elements - Swaps elements of a linked list
 *
 * @list: Head of the list
 * @Index: Index of the element to be removed
 *
 * Return: Nothing
 */
listint_t *swap_list_elements(listint_t **list, listint_t *swp)
{
	listint_t *p1, *p2;

	if (*list == NULL)
		return (NULL);
	p1 = p2 = *list;
	p2 = swp;
	p1 = p2->prev;
	if (p2 != NULL)
	{
		p1->next = p2->next;
		if (p2->next)
			(p2->next)->prev = p1;
		p2->next = p1;
		if (p1->prev)
			(p1->prev)->next = p2;
		else
			*list = p2;
		p2->prev = p1->prev;
		p1->prev = p2;
	}
	print_list(*list);
	return (*list);
}
/**
 * get_size - Returns the size of a list
 *
 * @list: Pointer to the head of the list
 *
 * Return: The size of the list
 */
size_t get_size(listint_t **list)
{
	unsigned int count = 0;
	listint_t *parse;

	parse = *list;
	while (parse != NULL)
	{
		parse = parse->next;
		count++;
	}
	return (count);
}

/**
 * insertion_sort_list - Sorts an array using insertion sort algorithm
 *
 * @array: Input list
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *parse, *swp;
	int sorted = 0;

	parse = *list;
	if (list == NULL)
		return;
	while (parse != NULL)
	{
		while (parse->prev != NULL)
		{
			swp = parse;
			if (parse->n < parse->prev->n)
				swap_list_elements(list, swp);
			if (parse->prev != NULL)
				parse = parse->prev;
			else	
				break;
		}
		if (parse == NULL)
		{
			parse = *list;
		}
		while (parse->next != NULL)
		{
			parse = parse->next;
			if (parse->n < (parse->prev)->n)
			{
				sorted = 0;
				break;
			}
			else
				sorted = 1;
		}
		if (sorted == 1 && parse->next == NULL)
			break;
	}
}
