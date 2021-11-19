/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:03:47 by emallah           #+#    #+#             */
/*   Updated: 2021/11/17 22:04:00 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	exec_child_cmd(t_ast *the_cmd, t_env_export *env_export,
			t_cmd_pipe *cmd_pipe, int i)
{
	pid_t	pid;

	g_global.global = 2;
	pid = fork();
	if (pid > 0)
		cmd_pipe->pid_child[i] = pid;
	if (pid == 0)
	{
		redirect_child_cmd(cmd_pipe, i);
		close(cmd_pipe->pipe_fd[0]);
		if (cmd_has_here_doc(the_cmd) == EXIT_SUCCESS)
			ft_cmd_pipe(the_cmd, env_export, cmd_pipe->heredoc_files_names[0]);
		else
			ft_cmd_pipe(the_cmd, env_export, NULL);
		close(cmd_pipe->pipe_fd[1]);
		close(cmd_pipe->fdin);
		exit(g_global.status);
	}
	close(cmd_pipe->fdin);
	cmd_pipe->fdin = cmd_pipe->pipe_fd[0];
	close(cmd_pipe->pipe_fd[1]);
}

void	redirect_child_cmd(t_cmd_pipe *cmd_pipe, int i)
{
	if (i == 0)
	{
		dup2(0, STDIN_FILENO);
		dup2(cmd_pipe->pipe_fd[1], STDOUT_FILENO);
	}
	else if (i == cmd_pipe->nbr_pipe)
	{
		dup2(cmd_pipe->fdin, STDIN_FILENO);
		dup2(1, STDOUT_FILENO);
	}
	else
	{
		dup2(cmd_pipe->fdin, STDIN_FILENO);
		dup2(cmd_pipe->pipe_fd[1], STDOUT_FILENO);
	}
}

int	ft_cmd_pipe(t_ast *s_ast, t_env_export *env_export, char *heredoc_file_name)
{
	if (s_ast->redir)
		return (ft_redir(s_ast, env_export, heredoc_file_name));
	return (ft_cmd(s_ast, env_export));
}

void	wait_for_child(t_cmd_pipe *cmd_pipe)
{
	int	status;
	int	i;

	i = 0;
	close(cmd_pipe->pipe_fd[0]);
	while (i <= cmd_pipe->nbr_pipe)
	{
		if (cmd_pipe->pid_child[i] != 0)
			waitpid(cmd_pipe->pid_child[i], &status, 0);
		i++;
	}
	g_global.status = WEXITSTATUS(status);
	if (WIFSIGNALED(status) && (WTERMSIG(status) + 128 != 141))
		g_global.status = WTERMSIG(status) + 128;
	g_global.global = 0;
	free(cmd_pipe->pid_child);
	if (cmd_pipe->heredoc_files_names_free != NULL)
		free_double(cmd_pipe->heredoc_files_names_free);
	free(cmd_pipe);
}
