/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 10:33:45 by bmetehri          #+#    #+#             */
/*   Updated: 2023/10/23 10:17:01 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/server.h"

int	ft_atoi(char *str)
{
	long	nbr;
	int		neg;

	nbr = 0;
	neg = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + (*str - 48);
		str++;
	}
	if (nbr == 2147483648 && neg < 0)
		return (-2147483648);
	return ((int)nbr * neg);
}

int	args_checker(int ac, char **av)
{
	int	idx;

	idx = 0;
	if (ac != 3)
		return (error_handler("Incompatible inupt !\n"));
	while (av[1][idx])
		if (!ft_isdigit(av[1][idx]))
			return (error_handler("Incopatible Pid\n"));
	return (0);
}

int	error_handler(char *str)
{
	ft_putstr(str);
	return (1);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
