#include "minishell.h"

int main(int ac, char **av, char **env)
{
	// -----------------------
	if (ac != 0)
	{
		printf("%s\n", av[0]);
		printf("%s\n=========\n", env[0]);
	}
	// -----------------------
	t_cmd	*cmds;

	cmds = (t_cmd *)ft_calloc(sizeof(t_cmd), 2);
	if (cmds == NULL)
		return (error(NULL));
	if (init_cmds(cmds, env) == EXIT_FAILURE
		|| ft_cmds(cmds) == EXIT_FAILURE)
	{
		free (cmds);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
	//printf("Minishell: %s:%s",cmd,strerror(errno));
}