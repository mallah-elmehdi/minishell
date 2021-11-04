/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_peek_next_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:38:39 by isghioua          #+#    #+#             */
/*   Updated: 2021/10/13 13:38:40 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	lexer_peek_next_char(t_lexer *s_lexer)
{
	char	next_char;

	if (s_lexer->content[s_lexer->index + 1] != '\0')
		next_char = s_lexer->content[s_lexer->index + 1];
	else
		next_char = '\0';
	return (next_char);
}
