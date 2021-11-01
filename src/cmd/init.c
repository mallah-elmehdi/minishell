#include "../../minishell.h"

t_cmd	*init_cmds(t_env_export *env_export, t_last_status *last_status)
{
	t_cmd	*cmds;

	cmds = (t_cmd *)ft_calloc(sizeof(t_cmd), 2);
	if (cmds == NULL)
		return (NULL);
	//cmds[0].arg = NULL;
	cmds[0].arg = ft_split("jjd d kkd dkjd dkd kd kdd k", ' ');
	cmds[0].cmd = ft_strdup("echo");
	cmds[0].env_export = env_export;
	cmds[0].last_status = last_status;
	return (cmds);
}

t_env_export	*init_env_export(const char **menv)
{
	t_env_export	*env_export;

	env_export = (t_env_export *)ft_calloc(sizeof(t_env_export), 2);
	if (env_export == NULL)
		return (NULL);
	env_export[0].env = init_env(menv);
	if (env_export[0].env == NULL)
	{
		free(env_export);
		return (NULL);
	}
	env_export[0].export = init_export(menv);
	if (env_export[0].export == NULL)
	{
		free(env_export[0].env);
		free(env_export);
		return (NULL);
	}
	return (env_export);
}

t_last_status	*init_last_status(void)
{
	t_last_status	*last_status;

	last_status = (last_status *)ft_calloc(sizeof(last_status), 2);
	if (last_status == NULL)
		return (NULL);
	last_status[0].last_status = 0;
	return (last_status);
}


// leaks here