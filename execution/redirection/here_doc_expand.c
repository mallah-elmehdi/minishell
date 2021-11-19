/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_expand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 02:45:46 by emallah           #+#    #+#             */
/*   Updated: 2021/11/18 02:45:49 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	exec_here_doc(t_ast *s_ast, t_env_export *env_export,
	char *heredoc_file_name)
{
	int	i;

	i = 0;
	while (s_ast->redir[i] != NULL)
	{
		if (g_global.here_doc_exit == 0)
		{
			if (s_ast->redir[i]->e_type == HERE_DOC_REDIR)
			{
				if (here_doc(env_export, s_ast->redir[i]->file_name,
						heredoc_file_name) == ERROR)
					return (ERROR);
			}
		}
		i++;
	}
	return (EXIT_FAILURE);
}

void	expand_line(t_env_export *env_export, char **line)
{
	char	*new_str;
	char	*cap_content;
	int		i;

	i = 0;
	cap_content = ft_strdup("");
	while ((*line)[i] != '\0')
	{
		if ((*line)[i] == '$')
			new_str = expand_dollar_sign(*line, &i, env_export->env);
		else
			new_str = ft_substr(*line, i, 1);
		i++;
		ft_strjoin_and_free(&cap_content, &new_str);
	}
	free(*line);
	*line = NULL;
	*line = cap_content;
}
