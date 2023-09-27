/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmetehri <bmetehri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:35:18 by bmetehri          #+#    #+#             */
/*   Updated: 2023/09/27 17:15:10 by bmetehri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/client.h"

int		wrd_cnt(char *str, char sep)
{
	int		count;
	bool	in_wrd;

	count = 0;
	while (*str)
	{
		in_wrd = false;
		while (*str == sep)
			str++;
		while(*str != sep && *str)
		{
			if (!in_wrd)
			{
				in_wrd = true;
				count++;
			}
			str++;
		}
	}
	return (count);
}

char	*get_next_word(char *str, char sep)
{
	static int	cursor;
	char		*next_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == sep)
		cursor++;
	while ((str[cursor + len] != sep) && str[cursor + len])
		len++;
	next_str = malloc(len * sizeof(char) + 1);
	if (!next_str)
		return (NULL);
	while (str[cursor] != sep && str[cursor])
		next_str[i++] = str[cursor++];
	next_str[i] = 0;
	return (next_str);
}

char	**fn_split(char *str, char sep)
{
	char	**tab;
	int		wrd_number;
	int		word_cnt;

	wrd_number = 0;
	word_cnt = wrd_cnt(str, sep);
	if (!word_cnt)
		exit(1);
	tab = malloc(sizeof(char *) * (word_cnt + 2));
	if (!tab)
		return (NULL);
	while (word_cnt-- >= 0)
	{
		if (wrd_number == 0)
		{
			tab[wrd_number] = malloc(sizeof(char));
			if (!tab[wrd_number])
				return (NULL);
			tab[wrd_number++][0] = '\0';
			continue ;
		}
		tab[wrd_number++] = get_next_word(str, sep);
	}
	tab[wrd_number++] = NULL;
	return (tab);
}

