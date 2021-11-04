/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:18:52 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 13:18:54 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

char	*ft_strdup(const char *str)
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

char	*ft_strdup_wout_quote(const char *str)
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
