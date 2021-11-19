/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_execute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:38:46 by isghioua          #+#    #+#             */
/*   Updated: 2021/11/17 04:08:42 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	parse_and_execute(t_lexer *s_lexer, t_env_export *env_export)
{
	t_token	*s_token;
	t_ast	*s_ast;

	s_token = tokenize(s_lexer);
	if (s_token->e_type == TOKEN_EOF)
	{
		free_token(&s_token);
		free_lexer(&s_lexer);
		return (0);
	}
	while (s_token->e_type != TOKEN_EOF)
	{
		s_ast = parse_command(&s_token, s_lexer, env_export->env);
		if (!s_ast)
		{
			g_global.status = 258;
			return (1);
		}
		execute_command(s_ast, env_export);
	}
	free_ast(&s_ast);
	free_token(&s_token);
	free_lexer(&s_lexer);
	return (0);
}
