/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 07:40:49 by bmetehri          #+#    #+#             */
/*   Updated: 2023/09/27 17:44:57 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/client.h"

int	main(int ac, char **av)
{
	int	server_pid;
	int	i;
	int	ii;

	i = 0;
	ii = 0;
	if (ac < 2 || !av || !*av)
		return (1);
	server_pid = ft_atoi(av[1]);
	av = fn_split(av[2], ' ');
	while (av[ii] != NULL)
	{
		printf("av[%d]: %s\n", ii, av[ii]);
		ii++;
	}
	printf("server_pid: %d\n", server_pid);
	while (av[2 + i] != NULL)
	{
		send_all(av, server_pid);
		if (av + 1 != NULL)
			send_space(server_pid);
		i++;
	}
	// if (kill(server_pid, SIGCHLD) == 0)
	// 	printf("Signal Sent Successfully\n");
	// else
	// 	printf("siganl failed to send");
	return (0);
}
