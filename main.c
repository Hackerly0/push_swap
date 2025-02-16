#include "push_swap.h"

void	ft_free(char **argv)
{
	int	i;

	i = 0;
	if (!argv)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free (argv);
}

char	**get_args(int argc, char *argv[], int *fr)
{
	if (argc == 2)
	{
		*fr = 1;
		return (ft_split(argv[1], 32));
	}
	*fr = 0;
	return (argv + 1);
}

int	handle_error(int argc, char *argv[], char ***args, int *fr)
{
	if (argc < 2 || (argc == 2 && !argv[1][0]))
	{
		ft_printf("Error\n");
		return (1);
	}
	*args = get_args(argc, argv, fr);
	if (check_args(*args, (argc == 2)))
	{
		write(1, "Duplicates found!\n", 18);
		if (*fr)
			ft_free(*args);
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;
	char	**args;
	int		fr;

	if (handle_error(argc, argv, &args, &fr))
		return (0);
	init_stack(&a, &b, args);
	if (!stack_sorted(&a))
		radix_sort(&a, &b);
	if (fr)
		ft_free(args);
	free_stack(&a);
	return (0);
}
