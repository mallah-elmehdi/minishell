/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:46:49 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 13:46:50 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

char	**init_env(const char **menv)
{
	int		i;
	char	**env;

	i = 0;
	env = (char **)ft_fcalloc(sizeof(char *), ft_fstrlen_double(menv) + 1);
	if (env == NULL)
		return (NULL);
	while (menv[i])
	{
		env[i] = ft_strdup(menv[i]);
		if (env[i] == NULL)
		{
			free_double(env);
			return (NULL);
		}
		i++;
	}
	return (env);
}
