#include "push_swap.h"

void	sort_three(t_node **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->data;
	b = (*stack)->next->data;
	c = (*stack)->next->next->data;
	if (a < b && b < c)
		return ;
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b > c && a > c)
		rra(stack);
}

int	find_smallest_index(t_node *stack)
{
	int	min;
	int	index;
	int	pos;

	min = stack->data;
	index = 0;
	pos = 0;
	while (stack)
	{
		if (stack->data < min)
		{
			min = stack->data;
			pos = index;
		}
		stack = stack->next;
		index++;
	}
	return (pos);
}

void	sort_five(t_node **a, t_node **b)
{
	int	pos;

	while (list_len(*a) > 3)
	{
		pos = find_smallest_index(*a);
		if (pos <= list_len(*a) / 2)
			while (pos--)
				ra(a);
		else
			while (pos++ < list_len(*a))
				rra(a);
		pb(a, b);
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}

void	sort_two(t_node **stack)
{
	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	if ((*stack)->data > (*stack)->next->data)
		sa(stack);
}
