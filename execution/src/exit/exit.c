/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:21:46 by emallah           #+#    #+#             */
/*   Updated: 2021/11/17 04:08:42 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	ft_exit(t_ast *s_ast)
{
	int		length;
	char	*trim_arg;

	length = ft_fstrlen_double((const char **)(s_ast->argv + 1));
	printf("exit\n");
	if (length == 0)
		exit(g_global.status);
	trim_arg = ft_strtrim(s_ast->argv[1], " ");
	if (valid_arg_exit(trim_arg) == EXIT_FAILURE)
	{
		prg_error(s_ast->argv[0], s_ast->argv[1], "numeric argument required");
		exit(255);
	}
	if (length == 1)
		exit(ft_fatoi(trim_arg));
	prg_error(s_ast->argv[0], NULL, "too many arguments");
	free(trim_arg);
	return (EXIT_SUCCESS);
}

int	valid_arg_exit(char *arg)
{
	int	i;

	i = 1;
	if (arg[0] != '-' && arg[0] != '+' && !ft_fisdigit(arg[0]))
		return (EXIT_FAILURE);
	while (arg[i])
	{
		if (!ft_fisdigit(arg[i]))
			return (EXIT_FAILURE);
		i++;
	}
	if (ft_fstrlen(arg) >= 19)
	{
		if (ft_atoi_exit(arg) == 0)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
