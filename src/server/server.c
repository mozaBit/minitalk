/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 07:40:49 by bmetehri          #+#    #+#             */
/*   Updated: 2023/10/17 11:05:58 by bmetehri         ###   ########.fr       */
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

	ft_printf("PID: %d\n", getpid());
	while (true)
		signal_configurator() ;
	return (0);
}

/*
 1- Get & Print the PID >>> Done
 2- Send a Signal from CLient to Server and well receive it and Print it
*/