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

int	calculate_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while ((size >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

int	binary_search_index(int *arr, int size, int value)
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

void	ft_quick_sort(int *arr, int start, int end)
{
	int	pivot;
	int	i;
	int	j;
	int	temp;

	if (start >= end)
		return ;
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

void	process_current_bit(t_node **a, t_node **b, int bit)
{
	int	size;
	int	i;

	i = 0;
	size = list_len(*a);
	while (i < size)
	{
		if (((*a)->indx >> bit) & 1)
			ra(a);
		else
			pb(a, b);
		i++;
	}
}
