#include "../../../minishell.h"

char	*try_all_paths(char **all_paths, char *cmd)
{
	int		i;
	char	*path_w_slash;
	char	*candidate_path;

	i = 0;
	while (all_paths[i])
	{
		path_w_slash = ft_strjoin(all_paths[i], "/");
		if (path_w_slash == NULL)
			return (NULL);
		candidate_path = ft_strjoin(path_w_slash, cmd);
		free(path_w_slash);
		if (candidate_path == NULL)
			return (NULL);
		if (access(candidate_path, F_OK) == 0)
			return (candidate_path);
		free(candidate_path);
		i++;
	}
	return (NULL);
}

char	*get_cmd_path(char *cmd, char **env)
{
	int		i;
	char	**all_paths;
	char	*cmd_path;

	i = 0;
	all_paths = NULL;
	while (env[i])
	{
		if (ft_fstrnstr(env[i], "PATH=", 5))
		{
			all_paths = ft_split(env[i] + 5, ':');
			if (all_paths == NULL)
				return (NULL);
			break ;
		}
		i++;
	}
	cmd_path = try_all_paths(all_paths, cmd);
	free_double(all_paths);
	return (cmd_path);
}

int	other(t_cmd *cmd)
{
	char	*the_cmd;

	if (cmd->cmd[0] == '/')
		the_cmd = ft_strdup(cmd->cmd);
	else
		the_cmd = get_cmd_path(cmd->cmd, cmd->env_export->env);
	if (the_cmd == NULL)
	{
		free (the_cmd);
		cmd->status->last_status = 1;
		return (prg_error(cmd->cmd, NULL, "command not found"));
	}
	if (execve(the_cmd, cmd->arg, cmd->env_export->env) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
