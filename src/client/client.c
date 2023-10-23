/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 07:40:49 by bmetehri          #+#    #+#             */
/*   Updated: 2023/10/23 19:02:54 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/server.h"

int	main(int ac, char **av)
{
	int	server_pid;

	config_csig();
	if (args_checker(ac, av))
		return (1);
	server_pid = ft_atoi(av[1]);
	send_message(server_pid, av[2]);
	return (0);
}
