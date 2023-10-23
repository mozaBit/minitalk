/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 09:59:46 by bmetehri          #+#    #+#             */
/*   Updated: 2023/10/23 17:58:17 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/server.h"

size_t	ft_print_in_hexa_max(unsigned long addr)
{
	int		i;
	size_t	j;
	char	*basem;
	char	tabaddr[17];

	if (!addr)
		return (ft_putstr("0"));
	i = 0;
	j = 0;
	basem = "0123456789ABCDEF";
	while (addr)
	{
		tabaddr[i] = basem[addr % 16];
		addr /= 16;
		i++;
	}
	i--;
	while (++i < 16)
		tabaddr[i] = 'z';
	i = 15;
	print_stuff(tabaddr, i, &j);
	return (j);
}

size_t	ft_print_in_hexa_min(unsigned long addr)
{
	int		i;
	size_t	j;
	char	*basem;
	char	tabaddr[17];

	if (!addr)
		return (ft_putstr("0"));
	i = 0;
	j = 0;
	basem = "0123456789abcdef";
	while (addr)
	{
		tabaddr[i] = basem[addr % 16];
		addr /= 16;
		i++;
	}
	i--;
	while (++i < 16)
		tabaddr[i] = 'z';
	i = 15;
	print_stuff(tabaddr, i, &j);
	return (j);
}

void	print_stuff(char *tabaddr, int i, size_t *j)
{
	while (i >= 0)
	{
		if (!(tabaddr[i] == 'z'))
			*j += ft_putchar(tabaddr[i]);
		i--;
	}
}

size_t	ft_print_void_p(void *pointer)
{
	unsigned long	addr;

	if (!pointer)
		return (ft_putstr("(nil)"));
	addr = (unsigned long)pointer;
	return (ft_putstr("0x") + ft_print_in_hexa_min(addr));
}

/*
size_t	ft_print_in_hexa(unsigned long addr, int det)
{
	int		i;
	size_t	j;
	char	*basem;
	char	*baseM;
	char	tabaddr[17];

	if (!addr)
		return (ft_putstr("0"));
	i = 0;
	j = 0;
	basem = "0123456789abcdef";
	baseM = "0123456789ABCDEF";
	while (addr)
	{
		if (det)
			tabaddr[i] = baseM[addr % 16];
		else
			tabaddr[i] = basem[addr % 16];
		addr /= 16;
		i++;
	}
	while (i < 16)
	{
		tabaddr[i] = 'z';
		i++;
	}
	i = 15;
	while (i >= 0)
	{
		if (!(tabaddr[i] == 'z'))
		{
			j++;
			write(1, &tabaddr[i], 1);
		}
		i--;
	}
	return (j);
}
*/
