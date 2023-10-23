/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:42:48 by bmetehri          #+#    #+#             */
/*   Updated: 2023/10/23 16:02:57 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/server.h"

void	signal_handler(int sig, siginfo_t *info, void *ucontext)
{
	static int				i = -1;
	static unsigned char	c;

	(void) ucontext;
	if (i == -1)
		i = 7;
	if (sig == SIGUSR1)
		c = c | (1 << i);
	i--;
	if (i < 0)
	{
		ft_putchar(c);
		c = 0;
		if (kill(info->si_pid, SIGUSR1) == -1)
			ft_putstr("Warning: Failed To send Back SIGUSR2\n");
	}
}

void	signal_configurator(void)
{
	struct sigaction	sa_act;

	sa_act.sa_flags = SA_SIGINFO;
	sa_act.sa_sigaction = &signal_handler;
	if (sigaction(SIGUSR1, &sa_act, NULL) == -1)
		ft_putstr("there is an error\n");
	if (sigaction(SIGUSR2, &sa_act, NULL) == -1)
		ft_putstr("there is an error\n");
}
