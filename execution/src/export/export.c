/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:22:30 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 14:22:32 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	ft_export(t_cmd *cmd)
{
	if (cmd->arg == NULL)
		return (print_export(cmd->env_export->export));
	else
		return (add_to_export(cmd));
	return (EXIT_SUCCESS);
}

int	print_export(char **export)
{
	int		i;

	i = 0;
	while (export[i])
	{
		if (ft_strbstr(export[i], "NaN") == NULL)
			printf("%s\n", export[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	add_to_export(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->arg[i])
	{
		if (valid_arg(cmd->arg[i]) == EXIT_SUCCESS)
		{
			if (ft_fstrnstr(cmd->arg[i], "=", 1))
			{
				if (add_env_export(cmd->env_export, cmd->arg[i])
					== EXIT_FAILURE)
					return (sys_error(cmd->cmd, cmd->arg[i]));
			}
			else if (add_export(cmd->env_export, cmd->arg[i]) == EXIT_FAILURE)
				return (sys_error(cmd->cmd, cmd->arg[i]));
		}
		i++;
	}
	return (valid_input(cmd));
}
