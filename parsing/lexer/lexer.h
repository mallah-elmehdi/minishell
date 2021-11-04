#ifndef LEXER_H
# define LEXER_H

t_lexer	*init_lexer(char *cmdline_buffer);
void	lexer_skip_whitespaces(t_lexer *s_lexer);
void	lexer_move_to_next_char(t_lexer *s_lexer);
char	lexer_peek_next_char(t_lexer *s_lexer);
char	*get_string(t_lexer *s_lexer);
char	*get_string_btw_quotes(t_lexer *s_lexer, char delimeter);
int		find_closing_quote(char *str, int index, char char_quote);

#endif
