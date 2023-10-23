/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:05:25 by bmetehri          #+#    #+#             */
/*   Updated: 2023/10/23 14:40:22 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/server.h"

void	send_message(int server_pid, char *message, int message_length)
{
	int				i;
	unsigned char	c;

	i = message_length;
	while (*message)
	{
		c = *message;
		i = 8;
		while (i--)
		{
			if (c & 0b10000000)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			c <<= 1;
			usleep(250);
		}
		message++;
	}
}

void	config_csig(void)
{
	struct sigaction	si_act;

	si_act.sa_flags = SA_SIGINFO;
	si_act.sa_handler = &csignal_handler;
	if (sigaction(SIGUSR1, &si_act, NULL) == -1)
		ft_putstr("there is an error\n");
	if (sigaction(SIGUSR2, &si_act, NULL) == -1)
		ft_putstr("there is an error\n");
}

void	csignal_handler(int sig)
{
	if (sig == SIGUSR2)
		ft_putstr("Received Signal!\n");
}
