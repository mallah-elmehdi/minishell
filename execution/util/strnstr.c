/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:19:15 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 13:19:16 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

char	*ft_fstrnstr(const char *str1, const char *str2, int n)
{
	int	i;
	int	a;

	i = 0;
	if (ft_fstrlen(str2) == 0)
		return ((char *)str1);
	while (str1[i])
	{
		a = 0;
		while (str1[i + a] == str2[a] && a < n)
		{
			a++;
			if (str2[a] == '\0')
				return (&((char *)str1)[i]);
		}
		i++;
	}
	return (NULL);
}

char	*ft_strbstr(const char *str1, const char *str2)
{
	int	i;

	i = 0;
	while (str2[i])
	{
		if (str1[i] != str2[i])
			return (NULL);
		i++;
	}
	return ((char *)str2);
}
