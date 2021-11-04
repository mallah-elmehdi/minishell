/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:17:29 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 13:17:33 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

long	ft_fatoi(const char *str)
{
	long		i;
	long		n;
	int			sign;

	i = 0;
	n = 0;
	sign = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
		if (str[i] >= 48 && str[i] <= 57 && str[i - 1] == '-')
			sign = -1;
	}
	if (str[i] < 48 && str[i] > 57)
		return (0);
	while (str[i] >= 48 && str[i] <= 57)
	{
		n = (n * 10) + (str[i] - 48);
		i++;
	}
	return (n * sign);
}
