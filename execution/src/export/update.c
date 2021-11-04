/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:22:40 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 14:22:45 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	update_export(char **export)
{
	if (update_export_old_pwd(export) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (update_export_pwd(export) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	update_export_old_pwd(char **export)
{
	char	*old_pwd;
	int		i;

	i = 0;
	old_pwd = get_old_pwd(export);
	if (old_pwd == NULL)
		return (EXIT_FAILURE);
	while (export[i])
	{
		if (ft_fstrnstr(export[i], "OLDPWD", 6))
		{
			free(export[i]);
			export[i] = ft_strjoin("declare -x OLDPWD=", old_pwd);
			free(old_pwd);
			if (export[i] == NULL)
				return (EXIT_FAILURE);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	update_export_pwd(char **export)
{
	int		i;
	char	*new_pwd;

	i = 0;
	new_pwd = pwd();
	if (new_pwd == NULL)
		return (EXIT_FAILURE);
	while (export[i])
	{
		if (ft_fstrnstr(export[i], "PWD", 3))
		{
			if (ft_fstrnstr(export[i], "OLDPWD", 6) == NULL)
			{
				free(export[i]);
				export[i] = ft_strjoin("declare -x PWD=", new_pwd);
				free(new_pwd);
				if (export[i] == NULL)
					return (EXIT_FAILURE);
				return (EXIT_SUCCESS);
			}
		}
		i++;
	}
	return (EXIT_FAILURE);
}
