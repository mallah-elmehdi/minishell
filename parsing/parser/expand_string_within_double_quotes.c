/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_string_within_double_quotes.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:16:07 by isghioua          #+#    #+#             */
/*   Updated: 2021/11/17 04:12:13 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	incremente_integers(int *i, int *j)
{
	*i += 1;
	*j += 1;
}

char	*expand_string_within_double_quotes(char **table_of_env_var,
		char *content)
{
	int		i;
	int		j;
	char	*str;
	char	*cap_content;

	if (ft_strchr(content, '$') == NULL)
		return (content);
	i = 0;
	cap_content = ft_strdup("");
	while (content[i])
	{
		j = 0;
		while (content[i] && content[i] != '$')
			incremente_integers(&i, &j);
		str = ft_substr(content, (i - j), j);
		ft_strjoin_and_free(&cap_content, &str);
		if (content[i] == '$')
		{
			str = expand_dollar_sign(content, &i, table_of_env_var);
			ft_strjoin_and_free(&cap_content, &str);
			i++;
		}
	}
	free(content);
	return (cap_content);
}
