#include "sort.h"

/**
 * swapNode - function that swap nodes
 * @fNode: first node
 * @sNode: second node
 * Return: Returns nothing
 */

void swapNode(listint_t *fNode, listint_t *sNode)
{
	if (fNode->prev)
		fNode->prev->next = sNode;
	if (sNode->next)
		sNode->next->prev = fNode;
	fNode->next = sNode->next;
	sNode->prev = fNode->prev;
	fNode->prev = sNode;
	sNode->next = fNode;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Cocktail shaker sort algorithm
 * @list: List of ints to sorted
 * Return: Returns nothing
 */

void cocktail_sort_list(listint_t **list)
{
    int swapped = 1;
	 listint_t *curr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = *list;
	while (swapped)
	{
		swapped = 0;
		while (curr && curr->next)
		{
			if (curr->n > curr->next->n)
			{
				swapNode(curr, curr->next);
				if (curr->prev->prev == NULL)
					*list = curr->prev;
				print_list(*list);
				swapped = 1;
			}
			else
				curr = curr->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		while (curr && curr->prev)
		{
			if (curr->n < curr->prev->n)
			{
				swapNode(curr->prev, curr);
				if (curr->prev == NULL)
					*list = curr;
				print_list(*list);
				swapped = 1;
			}
			else
				curr = curr->prev;
		}
	}
}

