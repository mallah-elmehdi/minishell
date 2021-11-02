#include "minishell.h"

int	main(int ac, char **av, char **menv)
{
	int				ret;
	t_cmd			*cmds;
	t_env_export	*env_export;
	t_last_status	*last_status;

	env_export = init_env_export((const char **)menv);
	if (env_export == NULL)
		return (sys_error(NULL, NULL, 1));
	last_status = init_last_status();
	if (last_status == NULL)
	{
		free(env_export);
		return (sys_error(NULL, NULL, 1));
	}
	cmds = init_cmds(&env_export[0], &last_status[0]);
	if (cmds == NULL)
	{
		free(env_export);
		free(last_status);
		return (sys_error(NULL, NULL, 1));
	}
	ret = ft_cmds(cmds);
	free_double(cmds[0].arg);
	free(cmds[0].cmd);
	free(cmds);
	free_double(env_export->env);
	free_double(env_export->export);
	free(env_export);
	free(last_status);
	return (ret);
}