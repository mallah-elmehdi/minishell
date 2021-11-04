#include "../../minishell.h"

void    fill_table_of_args(char **args, t_ast *s_cmd)
{
    int     i;
	int		k;
    int		size;
    char    **new_argv;

	if (s_cmd->argv == NULL)
	{
		size = get_size_of_table(args);
		s_cmd->argv = malloc(sizeof(char *) * (size + 1));
		ft_memcpy(s_cmd->argv, args, size);
		s_cmd->argv[size] = NULL;
		free(args);
	}
	else
	{
		i = get_size_of_table(s_cmd->argv);
		size = get_size_of_table(args);
		new_argv = malloc(sizeof(char *) * (i + size + 1));
		ft_memcpy(new_argv, s_cmd->argv, i);
		k = 0;
		while (k < size)
		{
			new_argv[i + k] = args[k];
			k++;
		}
		new_argv[i + k] = NULL;
		free(s_cmd->argv);
		s_cmd->argv = NULL;
		s_cmd->argv = new_argv;
		free(new_argv);
		new_argv = NULL;
	}
}
