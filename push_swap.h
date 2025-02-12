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
	int		indx;
	int		cost;
	long	data;
	bool	abv_med;
	bool	cheap;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*tar;
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

#endif