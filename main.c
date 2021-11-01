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
	// print_export(cmds[0].env_export->export);
	env(cmds[0].env_export->env);
	free_double(cmds[0].arg);
	free(cmds[0].cmd);
	free(cmds);
	free_double(env_export->env);
	free_double(env_export->export);
	free(env_export);
	return (ret);
}