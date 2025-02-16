#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void	reverse_rotate(t_node **head)
{
	t_node	*last;
	t_node	*second_last;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return ;
	last = NULL;
	second_last = *head;
	while (second_last->next->next != NULL)
		second_last = second_last->next;
	last = second_last->next;
	second_last->next = NULL;
	last->next = *head;
	*head = last;
}

void	rotate(t_node **list)
{
	t_node	*head;
	t_node	*tail;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return ;
	head = *list;
	tail = head;
	while (tail->next != NULL)
		tail = tail->next;
	*list = head->next;
	head->next = NULL;
	tail->next = head;
}

int	list_len(const t_node	*list)
{
	int	i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}
