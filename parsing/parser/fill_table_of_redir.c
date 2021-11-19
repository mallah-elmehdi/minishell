/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_table_of_redir.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:32:10 by isghioua          #+#    #+#             */
/*   Updated: 2021/11/05 21:34:35 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	fill_table_of_redir(t_ast *s_cmd, t_token **s_redir,
		t_token **s_filename, char *str)
{
	t_redir	*new_redir;
	t_redir	**table_of_redir;
	int		size;

	new_redir = init_redir(*s_redir, str);
	if (s_cmd->redir == NULL)
	{
		s_cmd->redir = malloc(sizeof(t_redir *) * 2);
		s_cmd->redir[0] = new_redir;
		s_cmd->redir[1] = NULL;
	}
	else
	{
		size = get_size_of_redir_table(s_cmd->redir);
		table_of_redir = ft_realloc_redir_table(s_cmd->redir, 1);
		table_of_redir[size] = new_redir;
		table_of_redir[size + 1] = NULL;
		s_cmd->redir = table_of_redir;
	}
	free_token(s_redir);
	free_token(s_filename);
}
