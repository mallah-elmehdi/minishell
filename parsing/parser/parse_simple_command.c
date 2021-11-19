/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_simple_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:43:24 by isghioua          #+#    #+#             */
/*   Updated: 2021/11/12 18:23:06 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_ast	*parse_simple_command(t_token **s_token, t_lexer *s_lexer,
		char	**table_of_env_var)
{
	t_ast	*s_cmd;

	s_cmd = init_ast(AST_SIMPLE_COMMAND);
	if ((*s_token)->e_type == TOKEN_PIPE)
	{
		printf("syntax error near unexpected token `|'\n");
		free_ast(&s_cmd);
		return (NULL);
	}
	while ((*s_token)->e_type != TOKEN_EOF && (*s_token)->e_type != TOKEN_PIPE)
	{
		if ((*s_token)->e_type == TOKEN_HERE_DOC_INPUT
			|| (*s_token)->e_type == TOKEN_REDIRECT_FILE_INPUT
			|| (*s_token)->e_type == TOKEN_APPEND_OUTPUT
			|| (*s_token)->e_type == TOKEN_OVERWRITE_OUTPUT)
		{
			add_redir_to_simple_cmd(s_lexer, s_token, &s_cmd, table_of_env_var);
			if (s_cmd == NULL)
				return (NULL);
		}
		else if ((*s_token)->e_type == TOKEN_STRING)
			add_arg_to_simple_cmd(s_token, s_lexer, &s_cmd, table_of_env_var);
	}
	return (s_cmd);
}
