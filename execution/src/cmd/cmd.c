/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:37:42 by emallah           #+#    #+#             */
/*   Updated: 2021/11/04 17:31:49 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	execute_command(t_ast *s_ast, t_env_export *env_export)
{
	char	*heredoc_file_name;

	if (s_ast->nbr_pipes > 0)
		return (ft_pipe(s_ast, env_export));
	if (s_ast->redir)
	{
		heredoc_file_name = ft_fstrdup("/tmp/heredoc");
		if (heredoc_file_name == NULL)
			return (sys_error(NULL, NULL));
		if (cmd_has_here_doc(s_ast) == EXIT_SUCCESS)
		{
			g_global.here_doc = 1;
			if (exec_here_doc(s_ast, env_export, heredoc_file_name) == ERROR)
				return (ERROR);
		}
		return (ft_redir(s_ast, env_export, heredoc_file_name));
	}
	return (ft_cmd(s_ast, env_export));
}

int	ft_cmd(t_ast *s_ast, t_env_export *env_export)
{
	int	ret;

	ret = EXIT_SUCCESS;
	if (s_ast->argv == NULL)
		return (EXIT_SUCCESS);
	if (g_global.here_doc_exit == 0)
	{
		ret = ft_cmd_phase_1(s_ast, env_export);
		if (ret == EXIT_FAILURE)
			ret = ft_cmd_phase_2(s_ast, env_export);
		if (ret == EXIT_FAILURE)
			ret = ft_cmd_phase_3(s_ast, env_export);
		if (ret == EXIT_FAILURE)
			ret = ft_cmd_phase_4(s_ast, env_export);
	}
	return (ret);
}
