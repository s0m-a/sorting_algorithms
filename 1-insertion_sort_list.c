#include "sort.h"

/**
* insertion_sort_list - sorts a doubly linked list of
* integers in ascending order
* @list: ptr to head of a doubly-linked list of ints
* Return : Returns nothing
*/

void insertion_sort_list(listint_t **list)
{
listint_t *current, *next = NULL;
listint_t *prev_c, *temp = NULL;
int limit = 0;

if (!list || !*list)
return;
temp = *list;
while (temp)
{
if (temp->prev != NULL)
{
current = temp;
limit = 0;

while (current && current->prev->n > current->n)
{

prev_c = current->prev;
next = current->next;
if (prev_c->prev)
prev_c->prev->next = current;
else
{
*list = current;
limit = 1;
}
if (next)
next->prev = prev_c;
prev_c = prev_c->prev;
current->next = prev_c;
prev_c->prev = current;
prev_c->next = next;
print_list(*list);
if (limit)
break;
}
}
temp = temp->next;
}
}
