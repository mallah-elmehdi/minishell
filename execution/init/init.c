#include "../../minishell.h"

t_cmd	*init(char **menv)
{
	t_cmd			*cmds;
	t_env_export	*env_export;
	t_last_status	*last_status;


	last_status = init_last_status();
	if (last_status == NULL)
		return (NULL);
	env_export = init_env_export(menv);
	if (env_export == NULL)
	{
		free(last_status);
		return (NULL);
	}
	return (init_cmds(env_export, last_status));
}