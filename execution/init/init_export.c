/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <emallah@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:23:54 by emallah           #+#    #+#             */
/*   Updated: 2021/11/15 15:23:55 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**init_export(const char **menv)
{
	int		*sorted;
	char	**export;

	sorted = sort_table(menv);
	if (sorted == NULL)
		return (NULL);
	export = (char **)ft_fcalloc(sizeof(char *), ft_fstrlen_double(menv) + 1);
	if (export == NULL)
	{
		free(sorted);
		return (NULL);
	}
	if (fill_export(menv, export, sorted) == ERROR)
		return (NULL);
	return (export);
}

int	*sort_table(const char **menv)
{
	int	i;
	int	temp;
	int	*sorted;

	i = 0;
	sorted = init_sort_table(menv);
	if (sorted == NULL)
		return (NULL);
	while (i < ft_fstrlen_double(menv) - 1)
	{
		if (ft_strcmp(menv[sorted[i]], menv[sorted[i + 1]]) > 0)
		{
			temp = sorted[i];
			sorted[i] = sorted[i + 1];
			sorted[i + 1] = temp;
			i = -1;
		}
		i++;
	}
	return (sorted);
}

int	*init_sort_table(const char **menv)
{
	int	i;
	int	*sorted;

	i = 0;
	sorted = (int *)ft_fcalloc(sizeof(int), ft_fstrlen_double(menv));
	if (sorted == NULL)
		return (NULL);
	while (menv[i])
	{
		sorted[i] = i;
		i++;
	}
	return (sorted);
}

int	fill_export(const char **menv, char **export, int *sorted)
{
	int		i;

	i = 0;
	while (menv[i])
	{
		export[i] = export_arg((char *)menv[sorted[i]]);
		if (export[i] == NULL)
		{
			free(sorted);
			free_double(export);
			return (ERROR);
		}
		i++;
	}
	free(sorted);
	return (EXIT_SUCCESS);
}

char	*export_arg(char *menv)
{
	char	**temp;
	char	*helper;
	char	*var_name;
	char	*out;

	temp = ft_fsplite(menv, '=');
	if (temp == NULL)
		return (NULL);
	helper = ft_fstrjoin("declare -x ", temp[0]);
	if (helper == NULL)
	{
		free_double(temp);
		return (NULL);
	}
	var_name = ft_fstrjoin(helper, "=");
	free(helper);
	if (var_name == NULL)
	{
		free_double(temp);
		return (NULL);
	}
	out = ft_fstrjoin_w_quote(var_name, temp[1]);
	free(var_name);
	free_double(temp);
	return (out);
}
