/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:14:35 by bmetehri          #+#    #+#             */
/*   Updated: 2023/10/23 17:58:04 by bmetehri         ###   ########.fr       */
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

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	args_checker(int ac, char **av)
{
	int	idx;

	idx = 0;
	if (ac != 3)
		return (error_handler("Error: Invalid inupt!\n"));
	if (kill(ft_atoi(av[1]), SIGUSR2) == -1)
		return (error_handler("Error: False Pid!\n"));
	while (av[1][idx])
	{
		if (!ft_isdigit(av[1][idx++]))
			return (error_handler("Error: Pid must be numerical!\n"));
	}
	return (0);
}
