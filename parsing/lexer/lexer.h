/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 12:41:16 by isghioua          #+#    #+#             */
/*   Updated: 2021/11/12 12:41:46 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

t_lexer	*init_lexer(char *cmdline_buffer);
void	lexer_skip_whitespaces(t_lexer *s_lexer);
void	lexer_move_to_next_char(t_lexer *s_lexer);
char	lexer_peek_next_char(t_lexer *s_lexer);
char	*get_string(t_lexer *s_lexer);
char	*get_string_btw_quotes(t_lexer *s_lexer, char delimeter);
int		find_closing_quote(char *str, int index, char char_quote);

t_token	*tokenize(t_lexer *s_lexer);
t_token	*init_token(int type, char *value);
t_token	*lexer_get_pipe_token(t_lexer *s_lexer);
t_token	*lexer_get_input_redir_token(t_lexer *s_lexer);
t_token	*lexer_get_output_redir_token(t_lexer *s_lexer);
t_token	*lexer_get_next_token(t_lexer *s_lexer);
t_token	*lexer_get_string(t_lexer *s_lexer);

#endif
