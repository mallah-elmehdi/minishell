/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:28:06 by emallah           #+#    #+#             */
/*   Updated: 2021/11/16 20:21:06 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_pipe(t_ast *s_ast, t_env_export *env_export)
{
	t_cmd_pipe	*cmd_pipe;
	t_ast		*the_cmd;
	int			i;

	i = 0;
	cmd_pipe = init_cmd_pipe(s_ast, env_export);
	if (cmd_pipe == NULL)
		return (sys_error(NULL, NULL));
	the_cmd = s_ast;
	while (i <= cmd_pipe->nbr_pipe)
	{
		the_cmd = the_cmd->child_cmd;
		if (i < cmd_pipe->nbr_pipe && pipe(cmd_pipe->pipe_fd) == -1)
			return (sys_error(NULL, NULL));
		exec_child_cmd(the_cmd, env_export, cmd_pipe, i);
		if (cmd_has_here_doc(the_cmd) == EXIT_SUCCESS)
			cmd_pipe->heredoc_files_names++;
		i++;
	}
	wait_for_child(cmd_pipe);
	return (EXIT_SUCCESS);
}

t_cmd_pipe	*init_cmd_pipe(t_ast *s_ast, t_env_export *env_export)
{
	t_cmd_pipe	*cmd_pipe;

	cmd_pipe = (t_cmd_pipe *)ft_fcalloc(sizeof(t_cmd_pipe), 2);
	if (cmd_pipe == NULL)
		return (NULL);
	cmd_pipe->pid_child = (int *)ft_calloc(sizeof(int), s_ast->nbr_pipes + 1);
	if (cmd_pipe->pid_child == NULL)
		return (NULL);
	cmd_pipe->heredoc_files_names = heredoc_files_names_all_cmd(s_ast);
	if (cmd_pipe->heredoc_files_names != NULL)
		exec_here_doc_all_cmd(s_ast, env_export, cmd_pipe->heredoc_files_names);
	cmd_pipe->fdin = -1;
	cmd_pipe->nbr_pipe = s_ast->nbr_pipes;
	cmd_pipe->heredoc_files_names_free = cmd_pipe->heredoc_files_names;
	return (cmd_pipe);
}
