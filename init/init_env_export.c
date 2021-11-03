#include "../minishell.h"

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