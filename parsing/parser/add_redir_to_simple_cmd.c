/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_redir_to_simple_cmd.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:15:46 by isghioua          #+#    #+#             */
/*   Updated: 2021/11/09 17:59:48 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	add_redir_to_simple_cmd(t_lexer *s_lexer, t_token **s_token,
		t_ast **s_cmd, char **table_of_env_var)
{
	t_token	*s_next_token;

	s_next_token = tokenize(s_lexer);
	if (s_next_token->e_type != TOKEN_STRING)
	{
		printf("Error Syntax\n");
		free_lexer(&s_lexer);
		free_token(s_token);
		free_token(&s_next_token);
		free_ast(s_cmd);
		return ;
	}
	add_redir_to_table_of_redirection(s_cmd, s_token, &s_next_token,
		table_of_env_var);
	*s_token = tokenize(s_lexer);
}
