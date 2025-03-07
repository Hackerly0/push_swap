/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oalhoora <oalhoora@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 09:11:45 by oalhoora          #+#    #+#             */
/*   Updated: 2024/09/12 14:44:57 by oalhoora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int a)
{
	if ((a >= '0' && a <= '9') || (a >= 'A' && a <= 'Z')
		|| (a >= 'a' && a <= 'z'))
		return (1);
	else
		return (0);
}
