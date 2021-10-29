#include "../../minishell.h"

t_cmd	*init_cmds(t_env_export *env_export)
{
	t_cmd	*cmds;

	cmds = (t_cmd *)ft_calloc(sizeof(t_cmd), 2);
	if (cmds == NULL)
		return (NULL);
	//cmds[0].arg = NULL;
	cmds[0].arg = ft_split("ER===============================sdfkmklfdlk ok sala=okokokko", ' ');
	cmds[0].cmd = ft_strdup("export");
	cmds[0].env_export = env_export;
	return (cmds);
}

t_env_export	*init_env_export(const char **menv)
{
	t_env_export	*env_export;
	int 			i;

	i = 0;
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

// leaks here