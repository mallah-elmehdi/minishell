/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <emallah@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:41:17 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 13:41:19 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	ft_echo(t_ast *s_ast)
{
	int	i;
	int	new_line;

	i = 1;
	new_line = 1;
	while (s_ast->argv[i])
	{
		if (valid_opt(s_ast->argv[i]) == EXIT_SUCCESS)
		{
			new_line = 0;
			i++;
		}
		else
			break ;
	}
	while (s_ast->argv[i])
	{
		printf("%s", s_ast->argv[i]);
		if (s_ast->argv[++i])
			printf(" ");
	}
	if (new_line)
		printf("\n");
	return (EXIT_SUCCESS);
}

int	valid_opt(char *opt)
{
	int	i;

	i = 1;
	if (opt == NULL || opt[0] != '-')
		return (EXIT_FAILURE);
	while (opt[i])
	{
		if (opt[i] != 'n')
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
