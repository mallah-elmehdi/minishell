#include "../../minishell.h"

void	add_redir_to_simple_cmd(t_lexer *s_lexer, t_token **s_token, t_ast *s_cmd, char **table_of_env_var)
{
	t_token	*s_next_token;

	s_next_token = tokenize(s_lexer);
	if (s_next_token->type != TOKEN_STRING)
	{
		printf("Error Syntax\n");
		//free_lexer(lexer);
		//free_token(s_token);
		//free_token(&s_next_token);
		//free_ast(s_cmd);
		exit(1);
	}
	//fill_table_of_redir(s_cmd, s_token, &s_next_token, table_of_env_var);
}
