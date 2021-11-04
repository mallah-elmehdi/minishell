/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:18:57 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 13:19:01 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

char	*ft_copy(char **temp, char *str, int length)
{
	int		i;
	int		j;
	int		k;
	char	*output;

	output = (char *)ft_fcalloc(sizeof(char), length);
	if (output == NULL)
		return (NULL);
	i = 0;
	j = ft_strcpy(output, str);
	while (temp[i])
	{
		k = 0;
		while (temp[i][k])
		{
			if (temp[i][k] != '"' && temp[i][k] != '\'' )
				output[j++] = temp[i][k];
			k++;
		}
		if (i == 0)
			output[j++] = '=';
		output[j++] = '"';
		i++;
	}
	return (output);
}

char	*ft_strjoin_w_quote(char *str1, char *str2)
{
	int		length;
	char	*output;
	char	**temp;

	length = ft_fstrlen(str1) + ft_fstrlen(str2) + 3;
	temp = ft_fsplit(str2, '=');
	if (temp == NULL)
		return (NULL);
	output = ft_copy(temp, str1, length);
	if (output == NULL)
	{
		free_double(temp);
		return (NULL);
	}
	free_double(temp);
	return (output);
}
