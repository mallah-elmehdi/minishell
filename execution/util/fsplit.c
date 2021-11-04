/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:18:29 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 13:18:36 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

char	*first_str(char *str, char delim)
{
	int		i;
	char	*first;

	i = 0;
	first = (char *)ft_fcalloc(sizeof(char), ft_fstrlen(str) + 1);
	if (first == NULL)
		return (NULL);
	while (str[i])
	{
		if (str[i] == delim)
			break ;
		first[i] = str[i];
		i++;
	}
	return (first);
}

char	*second_str(char *str, char delim)
{
	int		i;
	int		j;
	char	*second;

	i = 0;
	j = 0;
	second = (char *)ft_fcalloc(sizeof(char), ft_fstrlen(str) + 1);
	if (second == NULL)
		return (NULL);
	while (str[i] && str[i] != delim)
		i++;
	i++;
	while (str[i])
		second[j++] = str[i++];
	return (second);
}

char	**ft_fsplit(const char *str, char delim)
{
	char	**splited;

	if (str == NULL)
		return (NULL);
	splited = (char **)ft_fcalloc(sizeof (char *), 3);
	if (splited == NULL)
		return (NULL);
	splited[0] = first_str((char *)str, delim);
	if (splited[0] == NULL)
		return (free_splited(splited, 0));
	splited[1] = second_str((char *)str, delim);
	if (splited[1] == NULL)
		return (free_splited(splited, 1));
	return (splited);
}
