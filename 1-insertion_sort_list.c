#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked
 * list of integers by insertion sort
 * @list: list of integers
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j;

	if (!list)
		return;

	for (i = *list; i; i = i->next)
	{
		while (i->next && (i->n > i->next->n))
		{
			j = i->next;
			i->next = j->next;
			j->prev = i->prev;

			if (i->prev)
				i->prev->next = j;

			if (j->next)
				j->next->prev = i;

			i->prev = j;
			j->next = i;

			if (j->prev)
				i = j->prev;
			else
				*list = j;

			print_list(*list);
		}
	}
}
