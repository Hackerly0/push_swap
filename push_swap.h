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

typedef struct	s_node
{
	int				data;
	int				indx;
	struct s_node	*next;
}	t_node;

/*The indx var is for the index of the node, we need this in order to find the cheapest element.
  The cost var is for measuring the cost of pushing this element to the other stack.
  The data var is the number that is contained in this node.
  The abv_med is to check if the element is above median node, this is because if the more above median
    the cheaper it is to push.
  The cheap is check weather this node is the cheapest to push or not.
  The next & prev pointers is for the circular linked list.
  The tar pointer is the target node in the other stack (for the algorithm).*/

long	ft_atoll(char *s);
int		check_args(char **argv, int fr);
int		searchForNode(t_node **head, int value);
void    sa(t_node **headA);
void	sb(t_node **headB);
void	pa(t_node **headA, t_node **headB);
void	pb(t_node **headA, t_node **headB);
void    ra(t_node **headA);
void    rb(t_node **headB);
void	rr(t_node **headA, t_node **headB);
void    rra(t_node **headA);
void    rrb(t_node **headB);
void    rrr(t_node **headA, t_node **headB);
void	reverse_rotate(t_node **head);
void	rotate(t_node **list);
size_t	list_len(const t_node	*list);
int		stack_sorted(t_node **stack_a);
void    init_stack(t_node **a, char *argv[]);
void    free_stack(t_node **stack);
void	radix_sort(t_node **a, t_node **b);

#endif