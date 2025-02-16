/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handeling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnisirat <hnisirat@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:28:36 by hnisirat          #+#    #+#             */
/*   Updated: 2025/02/16 15:28:36 by hnisirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_last(t_node *head)
{
	while (head && head->next)
		head = head->next;
	return (head);
}

void	free_stack(t_node **stack)
{
	t_node	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}

static int	create_list(t_node **a, long num)
{
	t_node	*node;
	t_node	*last;

	if (!a)
		return (0);
	node = malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->next = NULL;
	node->data = num;
	if (!(*a))
		*a = node;
	else
	{
		last = find_last(*a);
		last->next = node;
	}
	return (1);
}

void	init_stack(t_node **a, t_node **b, char *argv[])
{
	int		i;
	long	num;

	i = -1;
	*a = NULL;
	*b = NULL;
	while (argv[++i])
	{
		num = ft_atoll(argv[i]);
		if (num == LONG_MAX)
		{
			ft_printf("Error\n");
			free_stack(a);
			exit(1);
		}
		if (!create_list(a, num))
		{
			ft_printf("Error\n");
			free_stack(a);
			exit(1);
		}
	}
}
