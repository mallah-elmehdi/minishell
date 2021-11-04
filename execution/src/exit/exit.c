/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:21:46 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 14:21:48 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	valid_arg_exit(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_exit(t_cmd *cmd)
{
	int	length;

	length = ft_fstrlen_double((const char **)cmd->arg);
	printf("exit\n");
	if (length == 0)
		exit(cmd->status->last_status);
	else if (valid_arg_exit(cmd->arg[0]) == EXIT_FAILURE)
	{
		prg_error(cmd->cmd, cmd->arg[0], "numeric argument required");
		exit (1);
	}
	else if (length == 1)
		exit(ft_fatoi(cmd->arg[0]));
	else
		return (prg_error_no_exit(cmd->cmd, "too many arguments"));
	return (EXIT_SUCCESS);
}
