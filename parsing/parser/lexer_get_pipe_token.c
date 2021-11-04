/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_get_pipe_token.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:37:53 by isghioua          #+#    #+#             */
/*   Updated: 2021/10/13 15:32:29 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token	*lexer_get_pipe_token(t_lexer *s_lexer)
{
	t_token	*s_token;
	char	*str;

	str = ft_substr(s_lexer->content, s_lexer->index, 1);
	lexer_move_to_next_char(s_lexer);
	s_token = init_token(TOKEN_PIPE, str);
	return (s_token);
}
