/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <emallah@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:28:02 by emallah           #+#    #+#             */
/*   Updated: 2021/11/15 17:28:03 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	exec_here_doc_all_cmd(t_ast *s_ast, t_env_export *env_export,
	char **heredoc_files_names)
{
	t_ast	*the_cmd;
	int		i;
	int		j;

	i = 0;
	j = 0;
	the_cmd = s_ast;
	while (i <= s_ast->nbr_pipes)
	{
		the_cmd = the_cmd->child_cmd;
		if (cmd_has_here_doc(the_cmd) == EXIT_SUCCESS)
		{
			g_global.here_doc = 1;
			if (exec_here_doc(the_cmd, env_export,
					heredoc_files_names[j++]) == ERROR)
				return (ERROR);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

char	*here_doc_file_name_gen(int j)
{
	char	*nbr;
	char	*file_name;

	nbr = ft_itoa(j);
	file_name = ft_fstrjoin("/tmp/heredoc-", nbr);
	free (nbr);
	return (file_name);
}

void	heredoc_file_name_fill(t_ast *s_ast, char **heredoc_files_names)
{
	t_ast	*the_cmd;
	int		i;
	int		j;

	i = 0;
	j = 0;
	the_cmd = s_ast;
	while (i <= s_ast->nbr_pipes)
	{
		the_cmd = the_cmd->child_cmd;
		if (cmd_has_here_doc(the_cmd) == EXIT_SUCCESS)
		{
			heredoc_files_names[j] = here_doc_file_name_gen(j);
			j++;
		}
		i++;
	}
}

char	**heredoc_files_names_all_cmd(t_ast *s_ast)
{
	char	**heredoc_files_names;
	int		length;

	length = nbr_here_doc_all_cmd(s_ast);
	if (length == -1)
		return (NULL);
	heredoc_files_names = (char **)ft_fcalloc(sizeof(char *), length + 1);
	if (heredoc_files_names == NULL)
		return (NULL);
	heredoc_file_name_fill(s_ast, heredoc_files_names);
	return (heredoc_files_names);
}

int	nbr_here_doc_all_cmd(t_ast *s_ast)
{
	t_ast	*the_cmd;
	int		i;
	int		length;

	the_cmd = s_ast;
	i = 0;
	length = 0;
	while (i <= s_ast->nbr_pipes)
	{
		the_cmd = the_cmd->child_cmd;
		if (cmd_has_here_doc(the_cmd) == EXIT_SUCCESS)
			length++;
		i++;
	}
	if (length == 0)
		return (-1);
	return (length);
}
