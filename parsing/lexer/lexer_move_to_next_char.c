/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_move_to_next_char.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:38:31 by isghioua          #+#    #+#             */
/*   Updated: 2021/10/13 13:38:32 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	lexer_move_to_next_char(t_lexer *s_lexer)
{
	if (s_lexer->current_char != '\0')
	{
		s_lexer->index += 1;
		s_lexer->current_char = s_lexer->content[s_lexer->index];
	}
}
