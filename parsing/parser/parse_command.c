/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:43:20 by isghioua          #+#    #+#             */
/*   Updated: 2021/11/09 19:43:06 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_ast	*error_pipe(t_ast **s_pipeline)
{
	printf("Error Syntax: Pipe at the end of CMDLINE\n");
	return (free_ast(s_pipeline));
}

t_ast	*parse_command(t_token **s_token, t_lexer *s_lexer,
		char **table_of_env_var)
{
	t_ast	*s_cmd;
	t_ast	*s_pipeline;

	s_pipeline = NULL;
	s_cmd = parse_simple_command(s_token, s_lexer, table_of_env_var);
	while (s_cmd && (*s_token)->e_type != TOKEN_EOF)
	{
		if (!s_pipeline)
			s_pipeline = init_ast(AST_PIPLINE_COMMAND);
		add_simple_cmd_to_pipeline(s_pipeline, s_cmd);
		free_token(s_token);
		*s_token = tokenize(s_lexer);
		if ((*s_token)->e_type == TOKEN_EOF)
			return (error_pipe(&s_pipeline));
		s_cmd = parse_simple_command(s_token, s_lexer, table_of_env_var);
		if (!s_cmd)
			return (free_ast(&s_pipeline));
		if ((*s_token)->e_type == TOKEN_EOF)
		{
			add_simple_cmd_to_pipeline(s_pipeline, s_cmd);
			return (s_pipeline);
		}
	}
	return (s_cmd);
}
