#include "../../minishell.h"

t_ast	*parse_command(t_token **s_token, t_lexer *s_lexer, char **table_of_env_var)
{
	//t_token *next_token;
	t_ast	*s_cmd;
	//t_ast	*s_pipeline;
	
	s_cmd = parse_simple_command(s_token, s_lexer, table_of_env_var);
	/*while (s_token->type  != TOKEN_EOF)
	{
		if (s_token->type == TOKEN_PIPE)
		{
			if (!s_pipeline)
				s_pipeline = init_ast(AST_PIPELINE);
			add_cmd_to_pipeline(s_pipeline, s_cmd);
			s_token = tokenize(s_lexer);
			if (s_token->type == TOKEN_EOF)
			{
				printf("Error Syntax: Pipe at the end of CMDLINE\n");
				//free_pipeline();
				exit (1);
			}
		}
		s_cmd = parse_simple_command(s_lexer, s_token);
		s_token = tokenize(s_lexer);
		if (s_token->type == TOKEN_EOF)
			add_cmd_to_pipeline(s_pipeline, s_cmd);
		return (s_pipeline);
	}*/
	return (s_cmd);
}
