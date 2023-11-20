#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of
 * integers in ascending order
 * @list: A pointer to the head of the doubly linked list
 *
 * Return: Nothing.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	cur = (*list)->next;

	while (cur != NULL)
	{
		listint_t *temp = cur;
		listint_t *next = cur->next;

		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;
			if (temp->prev == NULL)
				*list = temp;
			else
				temp->prev->next = temp;
			print_list(*list);
		}
		cur = next;
	}
}
