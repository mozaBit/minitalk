/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:05:25 by bmetehri          #+#    #+#             */
/*   Updated: 2023/09/27 17:23:54 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/client.h"

void	send_byte(char c, int pid){
	int		index;
	int		*tab;

	index = 8;
	tab = malloc(sizeof(int) * index);
	while (--index >= 0)
	{
		tab[index] = c % 2;
		c >>= 1;
		if (tab[index] != 0)
		{
			if (kill(pid, SIGUSR1) == 0)
				printf("Signal Sent Successfully\n");
			else
				printf("siganl failed to send\n");
		}
		else
		{
			if (kill(pid, SIGUSR2) == 0)
				printf("Signal Sent Successfully\n");
			else
				printf("siganl failed to send\n");
		}
	}
}

void	send_space(int	pid)
{
	kill(pid, SIGUSR1);
	kill(pid, SIGUSR2);
}

void	send_all(char **tab, int pid)
{
	char	*str;

	str = *tab;
	while (*str)
	{
		send_byte(*str, pid);
		str++;
	}
}
