/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlock_file_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:43:31 by isghioua          #+#    #+#             */
/*   Updated: 2021/11/09 18:58:45 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*unlock_file_name(char *content, char **table_of_env_var)
{
	char	*new_str;
	char	*cap_content;
	int		i;

	i = 0;
	cap_content = ft_strdup("");
	while (content[i] != '\0')
	{
		if (content[i] == '\'')
			new_str = extract_string_within_quotes(content, &i, '\'');
		else if (content[i] == '"')
			new_str = expand_string_within_double_quotes(table_of_env_var,
					extract_string_within_quotes(content, &i, '"'));
		else if (content[i] == '$')
			new_str = expand_dollar_sign(content, &i, table_of_env_var);
		else
			new_str = ft_substr(content, i, 1);
		i++;
		ft_strjoin_and_free(&cap_content, &new_str);
	}
	return (cap_content);
}
