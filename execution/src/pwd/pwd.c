/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:01:04 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 15:01:05 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

char	*pwd(void)
{
	char	*pwd;

	pwd = (char *)ft_fcalloc(sizeof(char), 256);
	if (pwd == NULL)
		return (NULL);
	pwd = getcwd(pwd, sizeof(char) * 256);
	if (pwd == NULL)
		return (NULL);
	return (pwd);
}

int	print_pwd(void)
{
	char	*path;

	path = pwd();
	if (path == NULL)
		return (EXIT_FAILURE);
	printf("%s\n", path);
	return (EXIT_SUCCESS);
}
