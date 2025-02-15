#include "push_swap.h"

int	stack_sorted(t_node **stack_a)
{
	t_node	*tmp;

	tmp = *stack_a;
	while (tmp -> next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int	calculate_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while ((size >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	optimize_rotations(t_node **a, int count)
{
	while (count--)
		rra(a);
}

static void	empty_stack_b(t_node **a, t_node **b)
{
	while (*b)
		pa(a, b);
}

static int	binary_search_index(int *arr, int size, int value)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = size - 1;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (arr[mid] == value)
			return (mid);
		else if (arr[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (-1);
}

static void	ft_quick_sort(int *arr, int start, int end)
{
	int	pivot;
	int	i;
	int	j;
	int	temp;

	if (start >= end)
		return;
	pivot = arr[end];
	i = start - 1;
	j = start - 1;
	while (++j < end)
	{
		if (arr[j] <= pivot)
		{
			i++;
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	temp = arr[i + 1];
	arr[i + 1] = arr[end];
	arr[end] = temp;
	ft_quick_sort(arr, start, i);
	ft_quick_sort(arr, i + 2, end);
}
static void	process_current_bit(t_node **a, t_node **b, int bit, int *rot_count)
{
	int	processed;
	int	current_size;

	current_size = list_len(*a);
	processed = -1;
	while (++processed < current_size)
	{
		if (((*a)->indx >> bit) & 1)
		{
			ra(a);
			(*rot_count)++;
		}
		else
			pb(a, b);
	}
}

static void	set_index(t_node **stack)
{
	t_node		*node;
	int			*arr;
	int			size;
	int			i;

	size = list_len(*stack);
	arr = malloc(sizeof(int) * size);
	if (!arr)
        return;
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

/* Optimized radix sort with rotation tracking */
void	radix_sort(t_node **a, t_node **b)
{
	int	bit;
	int	max_bits;
	int	size;
	int	rot_count;

	set_index(a);
	size = list_len(*a);
	max_bits = calculate_max_bits(size - 1);
	bit = -1;
	while (++bit < max_bits)
	{
		rot_count = 0;
		process_current_bit(a, b, bit, &rot_count);
		optimize_rotations(a, rot_count);
		empty_stack_b(a, b);
	}
}
