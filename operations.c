#include <stdio.h>
#include <stdlib.h>

typedef struct	s_list
{
	int data;
	struct s_list *next;
	struct s_list *prev;
}	t_list;

typedef struct  Node
{
	int				data;
	struct Node*	next;
}	Node;

typedef struct	Stack
{
	Node*	top;
}	Stack;

int	searchForNode(t_list **head, int value)
{
	t_list	*list;
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
		list = list -> next;
	}
	return (list);
}

void    sa(t_list **headA)
{
	t_list	*top;
	t_list	*temp;
	int		swap;

	if (headA == NULL || *headA == NULL || (*headA)->next == NULL)
		return ;
	top = *headA;
	temp = top->next;
	swap = top->data;
	top->data = temp->data;
	temp->data = swap;
	write(1, "sa", 2);
}

void	sb(t_list **headB)
{
	t_list	*top;
	t_list	*temp;
	int		swap;

	if (headB == NULL || *headB == NULL || (*headB)->next == NULL)
		return ;
	top = *headB;
	temp = top->next;
	swap = top->data;
	top->data = temp->data;
	temp->data = swap;
	write(1, "sb", 2);
}

void	pa(t_list **headA, t_list **headB)
{
	t_list	*topB;

	if (headB == NULL || *headB == NULL)
		return;
	topB = *headB;
	*headB = topB->next;
	topB->next = *headA;
	*headA = topB;
}

void	pb(t_list **headA, t_list **headB)
{
	t_list	*topA;

	if (headA == NULL || *headA == NULL)
		return ;
	topA = *headA;
	*headA = topA->next;
	topA->next = *headB;
	*headB = topA;
}

void    ra(t_list **headA)
{
	rotate(headA);
	write(1, "ra\n", 3);
}

void    rb(t_list **headB)
{
	rotate(headB);
	write(1, "rb\n", 3);
}

void	rr(t_list **headA, t_list **headB)
{
	rotate(headA);
	rotate(headB);
	write(1, "rr\n", 3);	
}

void    rra(t_list **headA)
{
	reverse_rotate(headA);
	write(1, "rra\n", 4);
}

void    rrb(t_list **headB)
{
	reverse_rotate(headB);
	write(1, "rrb\n", 4);
}

void    rrr(t_list **headA, t_list **headB)
{
	reverse_rotate(headA);
	reverse_rotate(headB);
	write(1, "rrr\n", 4);
}

void	reverse_rotate(t_list **head)
{
	t_list	*last;
	t_list	*secondLast;

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

void	rotate(t_list **list)
{
	t_list	*head;
	t_list	*tail;

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

size_t	list_len(const t_list	*list)
{
	size_t	i;

	i = 0;
	while(list)
	{
		list = list->next;
		i++;
	}
	return (i);
}
