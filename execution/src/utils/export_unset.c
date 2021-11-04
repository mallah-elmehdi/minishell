/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:08:50 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 15:08:52 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	valid_arg(char *arg)
{
	int	i;

	i = 1;
	if (!ft_isalpha(arg[0]) && arg[0] != '_')
		return (EXIT_FAILURE);
	while (arg[i])
	{
		if (!ft_isalnum(arg[i]) && arg[i] != '_')
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	valid_input(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (cmd->arg[i])
	{
		if (valid_arg(cmd->arg[i]) == EXIT_FAILURE)
			return (prg_error(cmd->cmd, cmd->arg[i],
					"not a valid identifier"));
		i++;
	}
	return (EXIT_SUCCESS);
}
