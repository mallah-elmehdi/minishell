/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:22:36 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 14:22:37 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

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

int	fill_export(const char **menv, char **export, int *sorted)
{
	int		i;

	i = 0;
	while (menv[i])
	{
		export[i] = ft_strjoin_w_quote("declare -x ", (char *)menv[sorted[i]]);
		if (export[i] == NULL)
		{
			free(sorted);
			free_double(export);
			return (EXIT_FAILURE);
		}
		i++;
	}
	free(sorted);
	return (EXIT_SUCCESS);
}

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
	if (fill_export(menv, export, sorted) == EXIT_FAILURE)
		return (NULL);
	return (export);
}
