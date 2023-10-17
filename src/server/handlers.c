/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:42:48 by bmetehri          #+#    #+#             */
/*   Updated: 2023/10/17 14:01:25 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/server.h"

void	signal_handler(int sig, siginfo_t *info, void *ucontext)
{
	static int				i;
	static unsigned char	c;

	(void) ucontext;
	i = 7;
	if (sig == SIGUSR1)
		c = c | (1 << 7);
	i--;
	if (i < 0)
	{
		ft_putchar(c);
		c = 0;
		i = 7;
		kill(info->si_pid, SIGUSR1);
	}
}

void	signal_configurator(){
	struct sigaction sa_act;

	sa_act.sa_flags = SA_SIGINFO;
	sa_act.sa_sigaction = &signal_handler;
	if (sigaction(SIGUSR1, &sa_act, NULL) == -1)
		write(1, "d", 1);
	if (sigaction(SIGUSR2, &sa_act, NULL) == -1)
		write(1, "d", 1);
}
