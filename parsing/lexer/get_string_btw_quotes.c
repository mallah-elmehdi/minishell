/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_btw_quotes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:33:53 by isghioua          #+#    #+#             */
/*   Updated: 2021/10/13 18:20:46 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*get_string_btw_quotes(t_lexer *s_lexer, char char_quote)
{
	char	*content;
	int		length;

	length = find_closing_quote(s_lexer->content, s_lexer->index, char_quote);
	if (length == 0)
	{
		length += 1;
		content = ft_substr(s_lexer->content, s_lexer->index, 1);
	}
	else
	{
		length += 2;
		content = ft_substr(s_lexer->content, s_lexer->index, length);
	}
	while (length > 0)
	{
		lexer_move_to_next_char(s_lexer);
		length--;
	}
	return (content);
}
