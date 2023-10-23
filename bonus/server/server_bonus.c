/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 07:40:49 by bmetehri          #+#    #+#             */
/*   Updated: 2023/10/23 18:00:57 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/server.h"
#include <signal.h>

/*
 * Le but est de creer un serveur en c qui print son PID
 * est receptione un message de la part d'un client
 * ce message est en format d'un signal
 * et il doit afficher le message recu
*/

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	while (true)
		signal_configurator();
	return (0);
}
