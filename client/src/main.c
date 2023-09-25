/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 07:40:49 by bmetehri          #+#    #+#             */
/*   Updated: 2023/09/25 11:38:45 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/client.h"

int	main(int ac, char **av)
{
	int	server_pid;

	if (ac < 2 || !av || !*av)
		return (1);
	server_pid = ft_atoi(av[1]);
	printf("server_pid: %d\n", server_pid);
	if (kill(server_pid, SIGCHLD) == 0)
		printf("Signal Sent Successfully\n");
	else
		printf("siganl failed to send");
	return (0);
}
