/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 07:39:08 by bmetehri          #+#    #+#             */
/*   Updated: 2023/10/23 10:15:07 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <unistd.h>
# include <stdbool.h>
# include <signal.h>
# include <stdlib.h>
# include <strings.h>
# include <stdarg.h>

/*
 * ft_printf
*/

int		ft_exec_flag(char *str, va_list args);
int		ft_printf(const char *str_format, ...);
size_t	ft_putnbr(int nbr);
size_t	ft_putunbr(unsigned int nbr);
size_t	ft_strlen(char *str);
size_t	ft_putstr(char *str);
size_t	ft_putchar(char c);
size_t	ft_print_in_hexa_min(unsigned long addr);
size_t	ft_print_in_hexa_max(unsigned long addr);
void	print_stuff(char *tabaddr, int i, size_t *j);
size_t	ft_print_void_p(void *pointer);

/*
 * handlers
*/
void	signal_handler(int sig, siginfo_t *info, void *ucontext);
void	signal_configurator(void);

/*
 * Utils Functions
*/
int		ft_atoi(char *str);
int		args_checker(int ac, char **av);
int		error_handler(char *str);
int		ft_isdigit(char c);

/*
 * Signal sending
*/
void	config_csig(void);
void	csignal_handler(int sig);
void	send_message(int server_pid, char *message, int message_length);

#endif
