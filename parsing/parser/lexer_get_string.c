/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_get_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:38:14 by isghioua          #+#    #+#             */
/*   Updated: 2021/10/13 18:21:12 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token	*lexer_get_string(t_lexer *s_lexer)
{
	char	*str;
	char	*cap_content;
	char	*content;

	cap_content = ft_strdup("");
	while (s_lexer->current_char != '\0' && s_lexer->current_char != '|'
		&& s_lexer->current_char != ' ' && s_lexer->current_char != '\t'
		&& s_lexer->current_char != '<' && s_lexer->current_char != '>')
	{
		if (s_lexer->current_char == '\'')
			str = get_string_btw_quotes(s_lexer, '\'');
		else if (s_lexer->current_char == '"')
			str = get_string_btw_quotes(s_lexer, '"');
		else
		{
			str = ft_substr(s_lexer->content, s_lexer->index, 1);
			lexer_move_to_next_char(s_lexer);
		}
		content = ft_strjoin(cap_content, str);
		free(str);
		free(cap_content);
		cap_content = content;
	}
	return (init_token(TOKEN_STRING, cap_content));
}
