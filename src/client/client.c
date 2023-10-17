/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 07:40:49 by bmetehri          #+#    #+#             */
/*   Updated: 2023/10/17 13:50:26 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/server.h"

int	main(int ac, char **av)
{
	int	server_pid;

	if (args_checker(ac, av))
		return (1);
	server_pid = ft_atoi(av[1]);
	config_csig();
	write(1, "here\n", 5);
	send_message(server_pid, av[2], ft_strlen(av[2]));
	while (1)
		pause();
	return (0);
}
