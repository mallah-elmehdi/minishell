/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size_of_redir_table.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:43:01 by isghioua          #+#    #+#             */
/*   Updated: 2021/11/05 21:49:32 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	get_size_of_redir_table(t_redir **table)
{
	int	i;

	i = 0;
	while (table[i])
		i++;
	return (i);
}
