#include "../../minishell.h"

t_cmd	*init_cmds(t_env_export *env_export, t_last_status *last_status)
{
	t_cmd	*cmds;

	cmds = (t_cmd *)ft_fcalloc(sizeof(t_cmd), 2);
	if (cmds == NULL)
		return (NULL);
	//cmds[0].arg = NULL;
	cmds[0].arg = ft_split("wc -l", ' ');
	cmds[0].cmd = ft_strdup("wc");
	cmds[0].env_export = env_export;
	cmds[0].status = last_status;
	return (cmds);
}