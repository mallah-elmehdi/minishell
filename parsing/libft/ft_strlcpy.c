/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:53:45 by isghioua          #+#    #+#             */
/*   Updated: 2019/10/19 14:02:58 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *buf, const char *s, size_t size)
{
	void	*r;
	size_t	i;
	size_t	count;

	if (buf == NULL)
		return (0);
	r = buf;
	count = ft_strlen(s);
	i = 0;
	while (i < size)
	{
		if (size && *s)
		{
			*(unsigned char *)r = *(unsigned char *)s;
			s++;
			r++;
		}
		*(unsigned char *)r = '\0';
		i++;
	}
	return (count);
}
