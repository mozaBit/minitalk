/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:42:48 by bmetehri          #+#    #+#             */
/*   Updated: 2023/10/16 20:17:41 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.h"
#include <signal.h>
#include <stdio.h>
#include <strings.h>



void	catch_sig(int signal)
{
	if (signal == SIGINT)
		write(1, "SIGUSR1 received\n", 18);
	if (signal == SIGQUIT)
		write(1, "SIGUSR2 received\n", 18);
}

void	signal_catcher(void)
{
	struct sigaction	act;

	bzero(&act, sizeof(act));

	act.sa_handler = &catch_sig;

	sigaction(SIGINT, &act, NULL);
	sigaction(SIGQUIT, &act, NULL);
}
