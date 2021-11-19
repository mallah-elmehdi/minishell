/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_get_output_redir_token.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:37:41 by isghioua          #+#    #+#             */
/*   Updated: 2021/10/13 15:32:33 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token	*lexer_get_output_redir_token(t_lexer *s_lexer)
{
	t_token	*s_token;
	char	*str;

	if (lexer_peek_next_char(s_lexer) == '>')
	{
		str = ft_substr(s_lexer->content, s_lexer->index, 2);
		lexer_move_to_next_char(s_lexer);
		lexer_move_to_next_char(s_lexer);
		s_token = init_token(TOKEN_APPEND_OUTPUT, str);
	}
	else
	{
		str = ft_substr(s_lexer->content, s_lexer->index, 1);
		lexer_move_to_next_char(s_lexer);
		s_token = init_token(TOKEN_OVERWRITE_OUTPUT, str);
	}
	return (s_token);
}
