/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:43:35 by emallah           #+#    #+#             */
/*   Updated: 2021/11/17 22:04:03 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	other(t_ast *s_ast, t_env_export *env_export)
{
	int		status;
	pid_t	pid;

	g_global.global = 1;
	pid = fork();
	if (pid == -1)
		return (ERROR);
	else if (pid == 0)
		run_cmd(s_ast, env_export);
	waitpid(pid, &status, 0);
	g_global.global = 0;
	if (WEXITSTATUS(status) != 0)
		g_global.status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status) && (WTERMSIG(status) + 128 != 141))
		g_global.status = WTERMSIG(status) + 128;
	return (EXIT_SUCCESS);
}

void	run_cmd(t_ast *s_ast, t_env_export *env_export)
{
	if (str_includes(s_ast->argv[0], '/') == EXIT_SUCCESS)
		rum_cmd_abs_path(s_ast, env_export);
	else
		rum_cmd_env_path(s_ast, env_export);
}
