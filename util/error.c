/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:17:43 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 13:17:45 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	sys_error(char *cmd, char *arg, int status)
{
	if (cmd)
		printf("minishell: %s: %s: %s\n", cmd, arg, strerror(errno));
	else
		printf("minishell: %s\n", strerror(errno));
	exit(status);
	return (EXIT_FAILURE);
}

int	prg_error(char *cmd, char *arg, char *msg, int status)
{
	if (arg)
		printf("minishell: %s: %s: %s\n", cmd, arg, msg);
	else
		printf("minishell: %s: %s\n", cmd, msg);
	exit(status);
	return (EXIT_FAILURE);
}

int	prg_error_no_exit(char *cmd, char *msg)
{
	printf("minishell: %s: %s\n", cmd, msg);
	return (EXIT_SUCCESS);
}
