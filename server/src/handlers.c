/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:42:48 by bmetehri          #+#    #+#             */
/*   Updated: 2023/09/27 11:32:43 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/server.h"

void	catch_sig(int signal)
{
	if (signal == SIGCHLD)
		printf("SIGCHLD received\n");
}

void	signal_catcher(void)
{
	struct sigaction	act;

	bzero(&act, sizeof(act));
	act.sa_handler = &catch_sig;
	sigaction(SIGCHLD, &act, NULL);
}
