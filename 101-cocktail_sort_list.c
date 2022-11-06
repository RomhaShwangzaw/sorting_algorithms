#include "sort.h"

/**
 * swap - swaps two nodes of a doubly linked list.
 * @a: the first node
 * @b: the second node
 */
void swap(listint_t *a, listint_t *b)
{
	listint_t *tmp;

	tmp = a->next;
	a->next = b->next;
	b->next = tmp;

	if (a->next != NULL)
		a->next->prev = a;
	if (b->next != NULL)
		b->next->prev = b;

	tmp = a->prev;
	a->prev = b->prev;
	b->prev = tmp;

	if (a->prev != NULL)
		a->prev->next = a;
	if (b->prev != NULL)
		b->prev->next = b;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Cocktail shaker sort algorithm.
 *
 * @list: a pointer to the head of the list.
 *
 * Description: You are not allowed to modify the integer n of a node.
 * You have to swap the nodes themselves.
 * You’re expected to print the list after each time you swap two elements.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head = *list, *node = NULL, *current = *list;
	int swap_count = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (head != NULL)
	{
		while (current->next != NULL)
		{
			node = current->next;
			if (current->n > node->n)
			{
				swap(current, node);
				if (node->prev == NULL)
					*list = node;
				swap_count++;
				print_list(*list);
				continue;
			}
			current = current->next;
		}
		while (current->prev != NULL)
		{
			node = current->prev;
			if (node->n > current->n)
			{
				swap(node, current);
				if (current->prev == NULL)
					*list = current;
				swap_count++;
				print_list(*list);
				continue;
			}
			current = current->prev;
		}
		if (swap_count == 0)
			return;
		swap_count = 0;
		head = head->next;
	}
}
