/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <emallah@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:44:02 by emallah           #+#    #+#             */
/*   Updated: 2021/11/15 15:44:04 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	str_includes(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (EXIT_SUCCESS);
		i++;
	}
	return (EXIT_FAILURE);
}

void	rum_cmd_abs_path(t_ast *s_ast, t_env_export *env_export)
{
	char		*the_cmd;
	struct stat	buf;

	the_cmd = ft_fstrdup(s_ast->argv[0]);
	if (stat(the_cmd, &buf) == -1)
	{
		free(the_cmd);
		sys_error(s_ast->argv[0], NULL);
		exit(127);
	}
	if (access(the_cmd, X_OK) == -1)
	{
		free(the_cmd);
		prg_error(s_ast->argv[0], NULL, "Permission denied");
		exit(126);
	}
	if (execve(the_cmd, s_ast->argv, env_export->env) == -1)
		exit(1);
}

void	rum_cmd_env_path(t_ast *s_ast, t_env_export *env_export)
{
	char	*the_cmd;

	the_cmd = get_cmd_path(s_ast->argv[0], env_export->env);
	if (the_cmd == NULL)
	{
		free(the_cmd);
		prg_error(s_ast->argv[0], NULL, "command not found");
		exit(127);
	}
	if (execve(the_cmd, s_ast->argv, env_export->env) == -1)
		exit(1);
}

char	*try_all_paths(char **all_paths, char *cmd)
{
	int		i;
	char	*path_w_slash;
	char	*candidate_path;

	i = 0;
	while (all_paths[i])
	{
		path_w_slash = ft_fstrjoin(all_paths[i], "/");
		if (path_w_slash == NULL)
			return (NULL);
		candidate_path = ft_fstrjoin(path_w_slash, cmd);
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
		if (ft_strbstr(env[i], "PATH="))
		{
			all_paths = ft_fsplit(env[i] + 5, ':');
			break ;
		}
		i++;
	}
	if (all_paths == NULL)
		return (NULL);
	cmd_path = try_all_paths(all_paths, cmd);
	free_double(all_paths);
	return (cmd_path);
}
