/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_redir_table.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:32:34 by isghioua          #+#    #+#             */
/*   Updated: 2021/11/05 21:41:41 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_redir	**ft_realloc_redir_table(t_redir **s_redir, int i)
{
	t_redir	**new_redir_table;
	int		size;
	int		j;

	j = 0;
	size = get_size_of_redir_table(s_redir);
	new_redir_table = malloc(sizeof(t_redir *) * (size + i + 1));
	while (j < size)
	{
		new_redir_table[j] = s_redir[j];
		j++;
	}
	free(s_redir);
	s_redir = NULL;
	return (new_redir_table);
}
