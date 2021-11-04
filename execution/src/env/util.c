/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:45:10 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 13:45:12 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	add_arg_env(t_env_export *env_export, char *arg)
{
	int		i;
	char	**temp;

	i = 0;
	temp = (char **)ft_fcalloc(sizeof(char *),
			ft_fstrlen_double((const char **)env_export->export) + 2);
	if (temp == NULL)
		return (EXIT_FAILURE);
	while (env_export->env[i])
	{
		temp[i] = ft_strdup(env_export->env[i]);
		if (temp[i] == NULL)
		{
			free_double(temp);
			return (EXIT_FAILURE);
		}
		i++;
	}
	temp[i] = ft_strdup_wout_quote(arg);
	temp[i + 1] = NULL;
	free_double(env_export->env);
	env_export->env = temp;
	return (EXIT_SUCCESS);
}
