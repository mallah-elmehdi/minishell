/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:19:04 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 13:19:06 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	ft_strlen_double(const char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}
