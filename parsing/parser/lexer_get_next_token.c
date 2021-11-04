/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_get_next_token.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:36:17 by isghioua          #+#    #+#             */
/*   Updated: 2021/10/13 15:32:43 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token	*lexer_get_next_token(t_lexer *s_lexer)
{
	if (s_lexer->current_char == '\0')
		return (init_token(TOKEN_EOF, ft_strdup("newline")));
	else if (s_lexer->current_char == '|')
		return (lexer_get_pipe_token(s_lexer));
	else if (s_lexer->current_char == '<')
		return (lexer_get_input_redir_token(s_lexer));
	else if (s_lexer->current_char == '>')
		return (lexer_get_output_redir_token(s_lexer));
	return (lexer_get_string(s_lexer));
}
