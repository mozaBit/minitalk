/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:42:48 by bmetehri          #+#    #+#             */
/*   Updated: 2023/09/27 17:25:38 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.h"

void	catch_sig(int signal)
{
	if (signal == SIGUSR1)
		printf("SIGUSR1 received\n");
	if (signal == SIGUSR2)
		printf("SIGUSR2 received\n");
}

void	signal_catcher(void)
{
	struct sigaction	act;

	bzero(&act, sizeof(act));
	act.sa_handler = &catch_sig;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
}
