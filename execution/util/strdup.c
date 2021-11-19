/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <emallah@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:18:52 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 13:18:54 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_fstrdup(const char *str)
{
	int		i;
	int		slen;
	char	*p;

	slen = ft_fstrlen((str)) + 1;
	p = (char *)ft_fcalloc(sizeof(char), slen);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (((char *)str)[i] != '\0')
	{
		p[i] = ((char *)str)[i];
		i++;
	}
	return (p);
}

char	*ft_fstrdup_wout_quote(const char *str)
{
	int		i;
	int		j;
	int		slen;
	char	*p;

	slen = ft_fstrlen((str)) + 1;
	p = (char *)ft_fcalloc(sizeof(char), slen);
	if (p == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (((char *)str)[i] != '\0')
	{
		if (((char *)str)[i] != '\'' && ((char *)str)[i] != '"')
			p[j++] = ((char *)str)[i];
		i++;
	}
	return (p);
}
