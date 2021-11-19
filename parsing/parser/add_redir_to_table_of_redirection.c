/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_redir_to_table_of_redirection.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:15:51 by isghioua          #+#    #+#             */
/*   Updated: 2021/11/09 17:55:10 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	add_redir_to_table_of_redirection(t_ast **s_cmd, t_token **s_redir,
		t_token **s_filename, char **table_of_env_var)
{
	int		i;
	char	*str;

	if ((*s_filename)->value[0] && ((*s_filename)->value[0] == '$'))
	{
		i = 0;
		str = expand_dollar_sign((*s_filename)->value, &i, table_of_env_var);
		i++;
		if ((*s_filename)->value[i] == '\0' && (ft_strncmp(str, "", 1) == 0
				|| (str && ft_strchr(str, ' '))))
		{
			free_token(s_redir);
			free_token(s_filename);
			free_ast(s_cmd);
			printf("ambiguous redirect\n");
			return ;
		}
		free(str);
		str = NULL;
		i = 0;
	}
	str = unlock_file_name((*s_filename)->value, table_of_env_var);
	fill_table_of_redir(*s_cmd, s_redir, s_filename, str);
}
