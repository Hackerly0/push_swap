#include "push_swap.h"

void	sa(t_node **stack_a)
{
	t_node	*top;
	t_node	*temp;
	int		swap;

	if (stack_a == NULL || *stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	top = *stack_a;
	temp = top->next;
	swap = top->data;
	top->data = temp->data;
	temp->data = swap;
	write(1, "sa\n", 3);
}

void	sb(t_node **stack_b)
{
	t_node	*top;
	t_node	*temp;
	int		swap;

	if (stack_b == NULL || *stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	top = *stack_b;
	temp = top->next;
	swap = top->data;
	top->data = temp->data;
	temp->data = swap;
	write(1, "sb\n", 3);
}

void	rra(t_node **headA)
{
	reverse_rotate(headA);
	write(1, "rra\n", 4);
}

void	rrb(t_node **headB)
{
	reverse_rotate(headB);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **headA, t_node **headB)
{
	reverse_rotate(headA);
	reverse_rotate(headB);
	write(1, "rrr\n", 4);
}
