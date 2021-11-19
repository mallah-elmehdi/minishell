/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:32:15 by isghioua          #+#    #+#             */
/*   Updated: 2021/11/09 19:43:13 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_ast	*free_ast(t_ast	**s_ast)
{
	t_ast	*s_simple_cmd;
	t_ast	*s_next_simple_cmd;

	if (!((*s_ast)->child_cmd))
		free_simple_cmd(*s_ast);
	else
	{
		while ((*s_ast)->child_cmd)
		{
			s_simple_cmd = (*s_ast)->child_cmd;
			s_next_simple_cmd = s_simple_cmd->child_cmd;
			free_simple_cmd(s_simple_cmd);
			free(s_simple_cmd);
			(*s_ast)->child_cmd = NULL;
			(*s_ast)->child_cmd = s_next_simple_cmd;
		}
	}
	free(*s_ast);
	*s_ast = NULL;
	return (NULL);
}
