#include "push_swap.h"

static void	set_index(t_node **stack)
{
	t_node		*node;
	int			*arr;
	int			size;
	int			i;

	size = list_len(*stack);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return ;
	node = *stack;
	i = -1;
	while (node && ++i < size)
	{
		arr[i] = node->data;
		node = node->next;
	}
	ft_quick_sort(arr, 0, size - 1);
	node = *stack;
	while (node)
	{
		node->indx = binary_search_index(arr, size, node->data);
		node = node->next;
	}
	free(arr);
}

void	radix_sort(t_node **a, t_node **b)
{
	int	bit;
	int	max_bits;
	int	size;

	if (list_len(*a) <= 2)
		sort_two(a);
	else if (list_len(*a) <= 3)
		sort_three(a);
	else if (list_len(*a) <= 5)
		sort_five(a, b);
	else
	{
		set_index(a);
		size = list_len(*a);
		max_bits = calculate_max_bits(size - 1);
		bit = 0;
		while (bit < max_bits)
		{
			process_current_bit(a, b, bit);
			while (*b)
				pa(a, b);
			bit++;
		}
	}
}
