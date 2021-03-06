/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <emallah@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:18:29 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 13:18:36 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	delim_length(char const *str, char delim)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (str[i])
	{
		if (str[i] == delim)
			length++;
		i++;
	}
	return (length);
}

char	**free_splited(char **splited, int i)
{
	while (i >= 0)
		free(splited[i--]);
	free(splited);
	return (NULL);
}

int	get_part(const char *str, char delim, int part)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (part == 0)
			return (i);
		if (str[i] == delim)
			part--;
		i++;
	}
	return (i);
}

char	*fill_str(const char *str, char delim, int part)
{
	char	*temp;
	int		j;
	int		k;

	k = 0;
	j = get_part(str, delim, part);
	temp = (char *)ft_fcalloc(sizeof(char), ft_fstrlen(str) + 1);
	if (temp == NULL)
		return (NULL);
	while (str[j])
	{
		if (str[j] == delim)
		{
			j++;
			break ;
		}
		temp[k++] = str[j++];
	}
	return (temp);
}

char	**ft_fsplit(const char *str, char delim)
{
	char	**splited;
	int		i;

	i = 0;
	if (str == NULL)
		return (NULL);
	splited = (char **)ft_fcalloc(sizeof (char *),
			delim_length(str, delim) + 2);
	if (splited == NULL)
		return (NULL);
	while (i < delim_length(str, delim) + 1)
	{
		splited[i] = fill_str(str, delim, i);
		if (splited[i] == NULL)
			return (free_splited(splited, i - 1));
		i++;
	}
	return (splited);
}
