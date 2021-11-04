/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:01:08 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 15:01:10 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

char	*get_old_pwd(char **env)
{
	int		i;
	char	**temp;
	char	*old_pwd;

	i = 0;
	while (env[i])
	{
		if (ft_fstrnstr(env[i], "PWD", 3))
		{
			temp = ft_split(env[i], '=');
			if (temp == NULL)
				return (NULL);
			old_pwd = ft_strdup(temp[1]);
			free_double(temp);
			if (old_pwd == NULL)
				return (NULL);
			return (old_pwd);
		}
		i++;
	}
	return (NULL);
}
