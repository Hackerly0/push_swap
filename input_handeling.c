#include "push_swap.h"
#include "ft_printf/ft_printf.h"
#include "ft_printf/Libft/libft.h"

static int	skip_spaces_sign(char **s)
{
	int	sign;

	sign = 1;
	while ((**s >= 9 && **s <= 13) || **s == 32)
		(*s)++;
	if (**s == '-' || **s == '+')
	{
		if (**s == '-')
			sign = -1;
		(*s)++;
	}
	return (sign);
}

long    ft_atoll(char *s)
{
    int		sign;
    long	num;

    num = 0;
    sign = 1;
    while ((*s >= 9 && *s <= 13) || *s == 32)
        s++;
    if (*s == '-' || *s == '+')
    {
        if (*s == '-')
            sign = -1;
        s++;
    }
    if (!(*s >= '0' && *s <= '9'))
        return (LONG_MAX);
    while (*s >= '0' && *s <= '9')
    {
        num = num * 10 + (*s - '0');
        s++;
        if ((num > LONG_MAX && sign == 1) || (num - 1 > LONG_MAX && sign == -1))
            return (LONG_MAX);
    }
    if (*s != '\0')
        return (LONG_MAX);
    return (num * sign);
}

int check_args(char **argv)
{
	int     i;
    int     j;

	i = 0;
	while (argv[++i])
	{
		if (ft_atoll(argv[i]) == LONG_MAX)
		{
            ft_printf("Error\n");
            return (1);
		}
		j = i;
		while (argv[++j])
		{
			if (ft_atoll(argv[j]) == LONG_MAX)
			{
                ft_printf("Error\n");
                return (1);
			}
			if (ft_atoll(argv[j]) == ft_atoll(argv[i]))
				return (1);
		}
	}
	return (0);
}
