#include "minishell.h"

int main(int argc, char **argv, char **arge)
{
	char	*cmdline_buf;
	t_env_export *env_export;
	t_lexer	*s_lexer;

	env_export = init_env_export((const char **)arge);
	while (1)
	{
		(void)argc;
		(void)*argv;
		cmdline_buf = readline("$ ");
		if (!cmdline_buf)
		{
			clear_history();
			exit(1);
		}
		if (cmdline_buf[0] != '\0')
		{
			add_history(cmdline_buf);
			s_lexer = init_lexer(cmdline_buf);
			parse_and_execute(s_lexer, env_export);
			free(cmdline_buf);
			free(s_lexer);
		}
	}
	clear_history();
	return (0);
}
