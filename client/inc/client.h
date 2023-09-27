/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 07:39:08 by bmetehri          #+#    #+#             */
/*   Updated: 2023/09/27 16:58:13 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H

# include <unistd.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <strings.h>

/*
 * Utils Functions
*/
int		ft_atoi(char *str);

/*
 * Split fn
*/
char	**fn_split(char *str, char sep);

/*
 * Signal sending
*/
void	send_all(char **tab, int pid);
void	send_space(int	pid);

#endif
