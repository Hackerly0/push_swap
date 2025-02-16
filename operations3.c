/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnisirat <hnisirat@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:28:32 by hnisirat          #+#    #+#             */
/*   Updated: 2025/02/16 15:28:33 by hnisirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **head_a, t_node **head_b)
{
	t_node	*top_b;

	if (head_b == NULL || *head_b == NULL)
		return ;
	top_b = *head_b;
	*head_b = top_b->next;
	top_b->next = *head_a;
	*head_a = top_b;
	write (1, "pa\n", 3);
}

void	pb(t_node **head_a, t_node **head_b)
{
	t_node	*top_a;

	if (head_a == NULL || *head_a == NULL)
		return ;
	top_a = *head_a;
	*head_a = top_a->next;
	top_a->next = *head_b;
	*head_b = top_a;
	write (1, "pb\n", 3);
}

void	ra(t_node **head_a)
{
	rotate (head_a);
	write (1, "ra\n", 3);
}

void	rb(t_node **head_b)
{
	rotate (head_b);
	write (1, "rb\n", 3);
}

void	rr(t_node **head_a, t_node **head_b)
{
	rotate (head_a);
	rotate (head_b);
	write (1, "rr\n", 3);
}
