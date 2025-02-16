/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handeling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnisirat <hnisirat@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:28:17 by hnisirat          #+#    #+#             */
/*   Updated: 2025/02/16 15:28:17 by hnisirat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_and_exit(char **s, int fr)
{
	int	i;

	if (!s || !fr)
		exit(1);
	i = -1;
	while (s[++i])
	{
		free(s[i]);
	}
	free(s);
	ft_printf("Error\n");
	exit(1);
}

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

long	ft_atoll(char *s)
{
	int		sign;
	long	num;

	num = 0;
	sign = skip_spaces_sign(&s);
	if (ft_strlen(s) > 11)
		return (INT_MAX);
	if (!(*s >= '0' && *s <= '9'))
		return (INT_MAX);
	while (*s >= '0' && *s <= '9')
	{
		num = num * 10 + (*s - '0');
		s++;
		if ((num > INT_MAX && sign == 1) || (num > INT_MAX && sign == -1))
			return (INT_MAX);
	}
	if (*s != '\0')
		return (INT_MAX);
	return (num * sign);
}

int	check_args(char **argv, int fr)
{
	int	i;
	int	j;

	i = -1;
	while (argv[++i])
	{
		if (ft_atoll(argv[i]) == INT_MAX)
			free_and_exit(argv, fr);
		j = i;
		while (argv[++j])
		{
			if (ft_atoll(argv[j]) == INT_MAX)
				free_and_exit(argv, fr);
			if (ft_atoll(argv[j]) == ft_atoll(argv[i]))
				free_and_exit(argv, fr);
		}
	}
	return (0);
}
