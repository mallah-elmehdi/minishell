/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:32:21 by isghioua          #+#    #+#             */
/*   Updated: 2021/11/05 21:40:46 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	free_simple_cmd(t_ast *s_simple_cmd)
{
	if (s_simple_cmd->argv)
		free_table_of_string(s_simple_cmd->argv);
	if (s_simple_cmd->redir)
		free_table_of_redir(s_simple_cmd->redir);
	s_simple_cmd->child_cmd = NULL;
}
