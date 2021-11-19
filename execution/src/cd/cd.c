/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <emallah@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:32:08 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 13:32:09 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	cd(t_ast *s_ast, t_env_export *env_export)
{
	char	*path;

	if (update_env_export_old_pwd(env_export) == ERROR)
		return (ERROR);
	path = cd_path(s_ast->argv[1], env_export->env);
	if (path == NULL)
		return (EXIT_SUCCESS);
	if (chdir(path) != 0)
	{
		free(path);
		return (ERROR);
	}
	free(path);
	if (update_env_export_pwd(env_export) == ERROR)
		return (ERROR);
	return (EXIT_SUCCESS);
}
