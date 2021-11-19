/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_env_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:47:08 by emallah           #+#    #+#             */
/*   Updated: 2021/11/18 17:47:10 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	new_export(t_env_export *env_export)
{
	char	**export;
	int		i;
	int		j;

	i = 0;
	j = 0;
	export = (char **)ft_fcalloc(sizeof(char *),
			ft_fstrlen_double((const char **)env_export->export) + 1);
	if (export == NULL)
		return (ERROR);
	while (env_export->export[i])
	{
		if (ft_strcstr(env_export->export[i], "NaN") == NULL)
			export[j++] = ft_fstrdup(env_export->export[i]);
		i++;
	}	
	free_double(env_export->export);
	env_export->export = export;
	return (EXIT_SUCCESS);
}

int	new_env(t_env_export *env_export)
{
	char	**env;
	int		i;
	int		j;

	i = 0;
	j = 0;
	env = (char **)ft_fcalloc(sizeof(char *),
			ft_fstrlen_double((const char **)env_export->env) + 1);
	if (env == NULL)
		return (ERROR);
	while (env_export->env[i])
	{
		if (ft_strcstr(env_export->env[i], "NaN") == NULL)
			env[j++] = ft_fstrdup(env_export->env[i]);
		i++;
	}	
	free_double(env_export->env);
	env_export->env = env;
	return (EXIT_SUCCESS);
}
