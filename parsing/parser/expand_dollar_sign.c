/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar_sign.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:16:02 by isghioua          #+#    #+#             */
/*   Updated: 2021/11/18 04:08:28 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*other_cases(int next_char, char *content, int index)
{
	char	*str;

	if (content[next_char] == '?')
		str = ft_itoa(g_global.status);
	else
		str = ft_substr(content, index, 2);
	return (str);
}

char	*expand_dollar_sign(char *content, int *index, char **table_of_env_var)
{
	int		next_char;
	char	*var_name;
	char	*str;
	int		j;

	next_char = *index + 1;
	if ((ft_isdigit(content[next_char]) == 0
			&& ft_isalnum(content[next_char]) > 0) || content[next_char] == '_')
	{
		j = 0;
		var_name = get_env_var_name(content, next_char, &j);
		str = get_env_var_value(var_name, j, table_of_env_var);
		free(var_name);
		*index += j;
	}
	else
	{
		if (content[next_char] == '\0')
			return (ft_strdup("$"));
		str = other_cases(next_char, content, *index);
		*index += 1;
	}
	return (str);
}
