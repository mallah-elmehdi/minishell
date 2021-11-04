/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:34:47 by isghioua          #+#    #+#             */
/*   Updated: 2021/10/13 13:34:48 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_lexer	*init_lexer(char *cmdline_buf)
{
	t_lexer	*s_lexer;

	s_lexer = malloc(sizeof(t_lexer));
	s_lexer->content = cmdline_buf;
	s_lexer->index = 0;
	s_lexer->current_char = cmdline_buf[s_lexer->index];
	return (s_lexer);
}
