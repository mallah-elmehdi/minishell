/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:41:17 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 13:41:19 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	ft_echo(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (ft_strbstr(cmd->arg[0], "-n"))
		i = 1;
	while (cmd->arg[i])
	{
		printf("%s", cmd->arg[i]);
		if (cmd->arg[++i])
			printf(" ");
	}
	if (ft_strbstr(cmd->arg[0], "-n") == NULL)
		printf("\n");
	return (EXIT_SUCCESS);
}
