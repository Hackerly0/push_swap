/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnisirat <hnisirat@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:28:42 by hnisirat          #+#    #+#             */
/*   Updated: 2025/02/16 15:28:42 by hnisirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include "ft_printf/ft_printf.h"
# include "ft_printf/Libft/libft.h"

typedef struct s_node
{
	int				data;
	int				indx;
	struct s_node	*next;
}	t_node;

long	ft_atoll(char *s);
int		check_args(char **argv, int fr);
void	sa(t_node **headA);
void	sb(t_node **headB);
void	pa(t_node **headA, t_node **headB);
void	pb(t_node **headA, t_node **headB);
void	ra(t_node **headA);
void	rb(t_node **headB);
void	rr(t_node **headA, t_node **headB);
void	rra(t_node **headA);
void	rrb(t_node **headB);
void	rrr(t_node **headA, t_node **headB);
void	reverse_rotate(t_node **head);
void	rotate(t_node **list);
int		list_len(const t_node	*list);
int		stack_sorted(t_node **stack_a);
void	init_stack(t_node **a, t_node **b, char *argv[]);
void	free_stack(t_node **stack);
void	radix_sort(t_node **a, t_node **b);
void	sort_three(t_node **stack);
int		find_smallest_index(t_node *stack);
void	sort_five(t_node **a, t_node **b);
void	sort_two(t_node **stack);
int		calculate_max_bits(int size);
int		binary_search_index(int *arr, int size, int value);
void	ft_quick_sort(int *arr, int start, int end);
void	process_current_bit(t_node **a, t_node **b, int bit);

#endif