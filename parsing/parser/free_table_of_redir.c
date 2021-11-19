/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_table_of_redir.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:32:25 by isghioua          #+#    #+#             */
/*   Updated: 2021/11/05 21:40:20 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_table_of_redir(t_redir **s_redir)
{
	int		i;

	i = 0;
	while (s_redir[i])
	{
		free(s_redir[i]->file_name);
		s_redir[i]->file_name = NULL;
		free(s_redir[i]);
		s_redir[i] = NULL;
		i++;
	}
	free(s_redir);
	s_redir = NULL;
}
