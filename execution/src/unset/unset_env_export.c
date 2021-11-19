/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env_export.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <emallah@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:07:33 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 15:07:34 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	unset_env_export(t_ast *s_ast, t_env_export *env_export)
{
	int	i;

	i = 1;
	while (s_ast->argv[i])
	{
		if (valid_arg_unset(s_ast->argv[i]) == EXIT_SUCCESS)
		{
			if (remove_arg_env_export(env_export, s_ast->argv[i])
				== EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		i++;
	}
	return (valid_input_unset(s_ast));
}

int	new_export_env(t_env_export *env_export)
{
	if (new_export(env_export) == ERROR)
		return (ERROR);
	if (new_env(env_export) == ERROR)
		return (ERROR);
	return (EXIT_SUCCESS);
}

int	remove_arg_env_export(t_env_export *env_export, char *arg)
{
	if (remove_arg_env(env_export, arg) == ERROR)
		return (ERROR);
	if (remove_arg_export(env_export, arg) == ERROR)
		return (ERROR);
	return (new_export_env(env_export));
}

int	remove_arg_env(t_env_export *env_export, char *arg)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_fstrjoin(arg, "=");
	if (temp == NULL)
		return (ERROR);
	while (env_export->env[i])
	{
		if (ft_strbstr(env_export->env[i], temp))
		{
			free(env_export->env[i]);
			free(temp);
			env_export->env[i] = ft_fstrdup("NaN");
			if (env_export->env[i] == NULL)
				return (ERROR);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	free(temp);
	return (EXIT_FAILURE);
}

int	remove_arg_export(t_env_export *env_export, char *arg)
{
	char	*temp0;
	char	*temp;
	int		ret;

	temp0 = ft_fstrjoin("declare -x ", arg);
	if (temp0 == NULL)
		return (ERROR);
	ret = delete_export_elements2(env_export->export, temp0);
	if (ret != EXIT_FAILURE)
	{
		free (temp0);
		return (ret);
	}
	temp = ft_fstrjoin(temp0, "=");
	free(temp0);
	if (temp == NULL)
		return (ERROR);
	ret = delete_export_elements(env_export->export, temp);
	free(temp);
	return (ret);
}
