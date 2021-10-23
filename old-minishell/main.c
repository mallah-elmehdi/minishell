#include "minishell.h"

int main(int ac, char **av, char **env)
{
	pid_t pid;
	char *line;
	char 	**env_list;

	pid = start_process();
	env_list = ft_env_list(env);
	if (pid == ERROR || !env_list)
		return (ERROR);
	while (1) {
		if (pid)
			break ;
		write(1, "minishell$ ", 12);
		while (!pid && !get_next_line(1, &line))
		{
			ft_parsing(line, env_list);
			free(line);
			break ;
		}
	}
	return (SUCCESS);
}
