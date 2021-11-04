/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:38:50 by isghioua          #+#    #+#             */
/*   Updated: 2021/10/13 15:31:13 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token	*tokenize(t_lexer *s_lexer)
{
	lexer_skip_whitespaces(s_lexer);
	return (lexer_get_next_token(s_lexer));
}
