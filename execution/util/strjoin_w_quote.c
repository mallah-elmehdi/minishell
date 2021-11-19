/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <emallah@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:18:57 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 13:19:01 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_copy(char *str1, char *str2, int length)
{
	int		i;
	int		j;
	char	*output;

	output = (char *)ft_fcalloc(sizeof(char), length);
	if (output == NULL)
		return (NULL);
	i = 0;
	j = ft_strcpy(output, str1);
	output[j++] = '"';
	while (str2[i])
	{
		if (str2[i] != '"' && str2[i] != '\'' )
			output[j++] = str2[i];
		i++;
	}
	output[j++] = '"';
	return (output);
}

char	*ft_fstrjoin_w_quote(char *str1, char *str2)
{
	int		length;
	char	*output;

	length = ft_fstrlen(str1) + ft_fstrlen(str2) + 3;
	output = ft_copy(str1, str2, length);
	if (output == NULL)
		return (NULL);
	return (output);
}
