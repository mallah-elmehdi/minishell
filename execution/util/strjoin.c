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

size_t	lenth(const char *s, const char *s0)
{
	if (s == NULL && s0 != NULL)
		return (ft_fstrlen(s0) + 1);
	else if (s != NULL && s0 == NULL)
		return (ft_fstrlen(s) + 1);
	else
		return (ft_fstrlen(s) + ft_fstrlen(s0) + 1);
}

char	*ft_strjoin(const char *s, const char *s0)
{
	char	*p;
	size_t	j;

	if (s == NULL && s0 == NULL)
		return (NULL);
	j = lenth(s, s0);
	p = (char *)ft_fcalloc(sizeof(char), j);
	if (p == NULL)
		return (NULL);
	while (s != NULL && *s != '\0')
		*p++ = *(char *)s++;
	while (s0 != NULL && *s0 != '\0')
		*p++ = *(char *)s0++;
	return (&p[-j + 1]);
}
