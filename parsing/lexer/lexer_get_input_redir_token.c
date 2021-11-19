/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_get_input_redir_token.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:34:50 by isghioua          #+#    #+#             */
/*   Updated: 2021/10/13 15:32:48 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token	*lexer_get_input_redir_token(t_lexer *s_lexer)
{
	t_token	*s_token;
	char	*str;

	if (lexer_peek_next_char(s_lexer) == '<')
	{
		str = ft_substr(s_lexer->content, s_lexer->index, 2);
		lexer_move_to_next_char(s_lexer);
		lexer_move_to_next_char(s_lexer);
		s_token = init_token(TOKEN_HERE_DOC_INPUT, str);
	}
	else
	{
		str = ft_substr(s_lexer->content, s_lexer->index, 1);
		lexer_move_to_next_char(s_lexer);
		s_token = init_token(TOKEN_REDIRECT_FILE_INPUT, str);
	}
	return (s_token);
}
