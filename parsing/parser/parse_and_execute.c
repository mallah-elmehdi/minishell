/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_execute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:38:46 by isghioua          #+#    #+#             */
/*   Updated: 2021/10/13 18:03:21 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	parse_and_execute(t_lexer *s_lexer, t_env_export *env_export)
{
	t_token	*s_token;
	t_ast	*s_ast;

	s_token = tokenize(s_lexer);
	if (s_token->type == TOKEN_EOF) // $       |
		return (0);
	while (s_token->type != TOKEN_EOF)
	{
		
		// if (;)
		s_ast = parse_command(&s_token, s_lexer, env_export->env);
		if (!s_ast)
		{
			//free_cmd_tree(s_ast);
			break ;
		}
		// execute_command(s_ast, env_export);		
		//free_cmd_tree(s_cmd);

		//	printf("Token[%d]=[%s]\n", s_token->type, s_token->value);
		//	s_token = tokenize(s_lexer);
	}
	//printf("Token[%d]=[%s]\n", s_token->type, s_token->value);
	return (1);
}
