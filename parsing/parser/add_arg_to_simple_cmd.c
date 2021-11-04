#include "../../minishell.h"

void	add_arg_to_simple_cmd(t_token **s_token, t_lexer *s_lexer, t_ast *s_cmd, char **table_of_env_var)
{
	char	**new_argv;
	int		size;
	
	if (s_cmd->argv == NULL)
	{
		s_cmd->argv = malloc(sizeof(char *) * 2);
		s_cmd->argv[0] = ft_strdup("");
		s_cmd->argv[1] = NULL;
	}
	else
	{
		size = get_size_of_table(s_cmd->argv);
		new_argv = ft_realloc_table(s_cmd->argv, 1);
		new_argv[size] = ft_strdup("");
		new_argv[size + 1] = NULL;
		s_cmd->argv = new_argv;
	}
	unlock_string((*s_token)->value, s_cmd, table_of_env_var);
	free((*s_token)->value);
	free(*s_token);
	*s_token = NULL;
	*s_token = tokenize(s_lexer);
}
