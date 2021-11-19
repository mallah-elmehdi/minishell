/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <emallah@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:01:57 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 15:01:59 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	ft_unset(t_ast *s_ast, t_env_export *env_export)
{
	if (ft_fstrlen_double((const char **)s_ast->argv) > 1)
		return (unset_env_export(s_ast, env_export));
	return (EXIT_SUCCESS);
}

int	delete_export_elements(char **export, char *temp)
{
	int	i;

	i = 0;
	while (export[i])
	{
		if (ft_strbstr(export[i], temp))
		{
			free(export[i]);
			export[i] = ft_fstrdup("NaN");
			if (export[i] == NULL)
				return (ERROR);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	return (EXIT_FAILURE);
}

int	delete_export_elements2(char **export, char *temp)
{
	int	i;

	i = 0;
	while (export[i])
	{
		if (ft_strcstr(export[i], temp))
		{
			free(export[i]);
			export[i] = ft_fstrdup("NaN");
			if (export[i] == NULL)
				return (ERROR);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	return (EXIT_FAILURE);
}
