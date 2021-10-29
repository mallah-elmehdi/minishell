#include "minishell.h"

int main(int ac, char **av, char **menv)
{
	if (ac != 0)
		printf("%s\n--------------------------------------------------------\n", av[0]);
	// -----------------------
	int				ret;
	t_cmd			*cmds;
	t_env_export	*env_export;

	env_export = init_env_export((const char **)menv);
	if (env_export == NULL)
		return (sys_error(NULL, NULL));
	cmds = init_cmds(&env_export[0]);
	if (cmds == NULL)
	{
		free(env_export);
		return (sys_error(NULL, NULL));
	}
	ret = ft_cmds(cmds);
	free(cmds);
	free(env_export);
	return (ret);
}