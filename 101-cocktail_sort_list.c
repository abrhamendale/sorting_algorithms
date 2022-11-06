#include "sort.h"

/**
 * swap_list_elements - Swaps elements of a linked list
 *
 * @list: Head of the list
 * @swp: Pointer to the element to be swapped
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
 * cocktail_sort_list - Sorts an array using bubble sort algorithm
 *
 * @list: Input list
 *
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	unsigned int size = 0;
	listint_t *parse;

	parse = (listint_t *)(*list);
	while (parse != NULL)
	{
		parse = parse->next;
		size++;
	}
	parse = (listint_t *)(*list);
	while (size)
	{
		while (parse->next != NULL)
		{
			/*printf("%d", parse->n);*/
			if (parse->n > (parse->next)->n)
			{
				*list = swap_list_elements(list, parse->next);
				parse = parse->prev;
			}
			parse = parse->next;
		}
		if (1)
		{
			parse = parse->prev;
			while (parse->prev != NULL)
			{
				/*printf("%d", parse->n);*/
				if (parse->n < (parse->prev)->n)
				{
					*list = swap_list_elements(list, parse);
					parse = parse->next;
				}
				parse = parse->prev;
			}
		}
		size--;
	}
}
