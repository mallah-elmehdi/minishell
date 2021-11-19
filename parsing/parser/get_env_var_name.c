/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_var_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:42:54 by isghioua          #+#    #+#             */
/*   Updated: 2021/11/05 21:46:11 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*get_env_var_name(char *content, int i, int *j)
{
	char	*var;

	while (content[i] && (ft_isalnum(content[i])
			|| ft_isdigit(content[i]) || content[i] == '_'))
	{
		i += 1;
		*j += 1;
	}
	var = ft_substr(content, (i - *j), *j);
	return (var);
}
