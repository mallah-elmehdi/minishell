/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_skip_whitespaces.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:38:42 by isghioua          #+#    #+#             */
/*   Updated: 2021/10/13 13:39:23 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	lexer_skip_whitespaces(t_lexer	*s_lexer)
{
	while (s_lexer->current_char != '\0')
	{
		if (s_lexer->current_char == ' '
			|| s_lexer->current_char == '\t')
			lexer_move_to_next_char(s_lexer);
		else
			break ;
	}
}
