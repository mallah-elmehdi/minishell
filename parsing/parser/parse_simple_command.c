#include "../../minishell.h"

t_ast	*parse_simple_command(t_token **s_token, t_lexer *s_lexer, char	**table_of_env_var)
{
	t_ast	*s_cmd;

	s_cmd = init_ast(AST_SIMPLE_COMMAND);
	if ((*s_token)->type == TOKEN_PIPE)
	{
		printf("syntax error near unexpected token `|'\n");
		exit(1);
	}
	int k = 0;
	while ((*s_token)->type != TOKEN_EOF && (*s_token)->type != TOKEN_PIPE)
	{
		if ((*s_token)->type == TOKEN_HERE_DOC_INPUT
				|| (*s_token)->type == TOKEN_REDIRECT_FILE_INPUT
				|| (*s_token)->type == TOKEN_APPEND_OUTPUT
				|| (*s_token)->type == TOKEN_OVERWRITE_OUTPUT)
			add_redir_to_simple_cmd(s_lexer, s_token, s_cmd, table_of_env_var);	
		else if ((*s_token)->type == TOKEN_STRING)
			add_arg_to_simple_cmd(s_token, s_lexer, s_cmd, table_of_env_var);
	}

	// int i = 0;
	// while (s_cmd->argv[i])
	// {
	// 	printf("%s\n", s_cmd->argv[i]);
	// 	i++;
	// }
	// int i = 0;
	// while (s_cmd->argv[i])
	// {
	// 	printf("%s\n", s_cmd->redir->file_name);
	// 	i++;
	// }
	return (s_cmd);	
}
