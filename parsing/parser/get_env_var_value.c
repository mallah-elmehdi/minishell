/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_var_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:42:57 by isghioua          #+#    #+#             */
/*   Updated: 2021/11/05 21:42:58 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*get_env_var_value(char *var, int size, char **table_of_env_var)
{
	int		i;
	char	*str;

	i = 0;
	while (table_of_env_var[i])
	{
		if (!ft_strncmp(table_of_env_var[i], var, size)
			&& table_of_env_var[i][size] == '=')
		{
			str = ft_substr(table_of_env_var[i], (size + 1),
					ft_strlen(table_of_env_var[i]) - size - 1);
			return (str);
		}
		else
			i++;
	}
	return (ft_strdup(""));
}
