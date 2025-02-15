#include "push_swap.h"

int main(int argc, char *argv[])
{
    t_node	*a;
    t_node	*b;
    int			fr;

	fr = 0;
    if ((argc == 1) || (argc == 2 && argv[1][0] == '\0'))
    {
        ft_printf("Error\n");
        return (1);
    }
    if (argc == 2)
    {
        argv = ft_split(argv[1], 32);
		fr = 1;
    }
    if (check_args(argv, fr))
    {
        write(1, "Duplicates found!\n", 18);
        return (0);
    }
    init_stack(&a, argv);
	if (!stack_sorted(&a))
        radix_sort(&a, &b);
	free_stack(&a);
	return (0);
}