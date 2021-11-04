#ifndef	TOKENS_H
# define TOKENS_H

t_token *tokenize(t_lexer *s_lexer);
t_token *init_token(int type, char *value);
t_token	*lexer_get_pipe_token(t_lexer *s_lexer);
t_token	*lexer_get_input_redir_token(t_lexer *s_lexer);
t_token	*lexer_get_output_redir_token(t_lexer *s_lexer);
t_token	*lexer_get_next_token(t_lexer *s_lexer);
t_token	*lexer_get_string(t_lexer *s_lexer);
int		parse_and_execute(t_lexer *s_lexer, t_env_export *env_export);
t_ast	*init_ast(int type);
t_ast	*parse_command(t_token **s_token, t_lexer *s_lexer, char **table_of_env_var);
t_ast	*parse_simple_command(t_token **s_token, t_lexer *s_lexer, char **table_of_env_var);

void	add_arg_to_simple_cmd(t_token **s_token, t_lexer *s_lexer, t_ast *s_cmd, char **table_of_env_var);
void	add_redir_to_simple_cmd(t_lexer *s_lexer, t_token **s_token, t_ast *s_cmd, char **table_of_env_var);
void	add_simple_cmd_to_pipeline(t_ast *s_parent, t_ast *s_child);
void    add_string_to_table_of_args(char **cap_content, t_ast *s_cmd);

char	*expand_dollar_sign(char *content, int *index, char **table_of_env_var);
char	*get_env_var_value(char *var, int size, char **table_of_env_var);
char    *get_env_var_name(char *content, int i, int *j);
char    *expand_string_within_double_quotes(char **table_of_env_var, char *content);
char    *extract_string_within_dollar_sign(t_ast *s_cmd, char **str_before, char *content);
char	*extract_string_within_quotes(char *content, int *index, char char_quote);

int		get_size_of_table(char **table);

void    fill_table_of_args(char **args, t_ast *s_cmd);
//void	fill_table_of_redir(t_ast *s_cmd, t_token *s_redir, t_token *s_filename, char **table_of_env_var);

void	unlock_string(char *content, t_ast *cmd, char **table_of_env_var);

char	**ft_realloc_table(char **args, int size);

#endif
