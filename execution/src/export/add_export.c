/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <emallah@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:38:29 by emallah           #+#    #+#             */
/*   Updated: 2021/11/15 15:38:30 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	add_export(t_env_export *env_export, char *arg)
{
	if (export_exist(env_export->export, arg) == EXIT_SUCCESS)
		return (EXIT_SUCCESS);
	else
		return (push_arg_export(env_export, arg));
	return (EXIT_SUCCESS);
}

int	push_arg_export(t_env_export *env_export, char *arg)
{
	int		i;
	char	**temp;

	i = 0;
	temp = (char **)ft_fcalloc(sizeof(char *),
			ft_fstrlen_double((const char **)env_export->export) + 2);
	if (temp == NULL)
		return (ERROR);
	while (env_export->export[i])
	{
		temp[i] = ft_fstrdup(env_export->export[i]);
		if (temp[i] == NULL)
		{
			free_double(temp);
			return (ERROR);
		}
		i++;
	}
	temp[i] = ft_fstrjoin("declare -x ", arg);
	temp[i + 1] = NULL;
	free_double(env_export->export);
	env_export->export = temp;
	return (EXIT_SUCCESS);
}
