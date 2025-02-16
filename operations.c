#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

int	searchForNode(t_node **head, int value)
{
	t_node	*list;
	int		i;

	if (head == NULL || *head == NULL)
		return (-1);
	list = *head;
	i = 0;
	while (list != NULL)
	{
		if (list -> data == value)
			return (i);
		i++;
		list = list->next;
	}
	return (i);
}

void    sa(t_node **headA)
{
	t_node	*top;
	t_node	*temp;
	int		swap;

	if (headA == NULL || *headA == NULL || (*headA)->next == NULL)
		return ;
	top = *headA;
	temp = top->next;
	swap = top->data;
	top->data = temp->data;
	temp->data = swap;
	write(1, "sa\n", 3);
}

void	sb(t_node **headB)
{
	t_node	*top;
	t_node	*temp;
	int		swap;

	if (headB == NULL || *headB == NULL || (*headB)->next == NULL)
		return ;
	top = *headB;
	temp = top->next;
	swap = top->data;
	top->data = temp->data;
	temp->data = swap;
	write(1, "sb\n", 3);
}

void	pa(t_node **headA, t_node **headB)
{
	t_node	*topB;

	if (headB == NULL || *headB == NULL)
		return;
	topB = *headB;
	*headB = topB->next;
	topB->next = *headA;
	*headA = topB;
	write(1, "pa\n", 3);
}

void	pb(t_node **headA, t_node **headB)
{
	t_node	*topA;

	if (headA == NULL || *headA == NULL)
		return ;
	topA = *headA;
	*headA = topA->next;
	topA->next = *headB;
	*headB = topA;
	write(1, "pb\n", 3);
}

void    ra(t_node **headA)
{
	rotate(headA);
	write(1, "ra\n", 3);
}

void    rb(t_node **headB)
{
	rotate(headB);
	write(1, "rb\n", 3);
}

void	rr(t_node **headA, t_node **headB)
{
	rotate(headA);
	rotate(headB);
	write(1, "rr\n", 3);	
}

void    rra(t_node **headA)
{
	reverse_rotate(headA);
	write(1, "rra\n", 4);
}

void    rrb(t_node **headB)
{
	reverse_rotate(headB);
	write(1, "rrb\n", 4);
}

void    rrr(t_node **headA, t_node **headB)
{
	reverse_rotate(headA);
	reverse_rotate(headB);
	write(1, "rrr\n", 4);
}

void	reverse_rotate(t_node **head)
{
	t_node	*last;
	t_node	*secondLast;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;
	last = NULL;
	secondLast = *head;
	while (secondLast->next->next != NULL)
		secondLast = secondLast->next;
	last = secondLast->next;
	secondLast->next = NULL;
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
	while(list)
	{
		list = list->next;
		i++;
	}
	return (i);
}
