/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <emallah@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:38:33 by emallah           #+#    #+#             */
/*   Updated: 2021/11/15 15:38:36 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	arg_w_equal(t_ast *s_ast, t_env_export *env_export, int i)
{
	char	**temp;

	temp = ft_fsplite(s_ast->argv[i], '=');
	if (temp == NULL)
		return (ERROR);
	if (valid_arg_export(temp[0]) == EXIT_SUCCESS)
	{
		if (add_env_export(env_export, temp) == ERROR)
			return (sys_error(s_ast->argv[0], s_ast->argv[i]));
	}
	else
	{
		prg_error(s_ast->argv[0], s_ast->argv[i], "not a valid identifier");
		free_double(temp);
	}
	return (EXIT_SUCCESS);
}

int	add_to_export(t_ast *s_ast, t_env_export *env_export)
{
	int		i;

	i = 1;
	while (s_ast->argv[i])
	{
		if (ft_fstrnstr(s_ast->argv[i], "=", 1))
		{
			if (arg_w_equal(s_ast, env_export, i) == ERROR)
				return (ERROR);
		}
		else
		{
			if (valid_arg_export(s_ast->argv[i]) == EXIT_SUCCESS)
			{
				if (add_export(env_export, s_ast->argv[i]) == ERROR)
					return (sys_error(s_ast->argv[0], s_ast->argv[i]));
			}
			else
				prg_error(s_ast->argv[0], s_ast->argv[i],
					"not a valid identifier");
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
