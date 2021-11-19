/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unlock_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:43:35 by isghioua          #+#    #+#             */
/*   Updated: 2021/11/17 23:45:47 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	unlock_string(char *content, int *i, t_ast **s_cmd,
			char **table_of_env_var)
{
	char	*new_str;
	char	*cap_content;

	cap_content = ft_strdup("");
	while (content[*i] != '\0')
	{
		if (content[*i] == '\'')
			new_str = extract_string_within_quotes(content, i, '\'');
		else if (content[*i] == '"')
			new_str = expand_string_within_double_quotes(table_of_env_var,
					extract_string_within_quotes(content, i, '"'));
		else if (content[*i] == '$')
		{
			new_str = extract_string_within_dollar_sign(s_cmd, &cap_content,
					expand_dollar_sign(content, i, table_of_env_var));
			if (!new_str && content[*i + 1] == '\0')
				return (delete_string_from_table_of_args(s_cmd,
						&new_str, &cap_content));
		}
		else
			new_str = ft_substr(content, *i, 1);
		(*i) += 1;
		ft_strjoin_and_free(&cap_content, &new_str);
	}
	add_string_to_table_of_args(&cap_content, s_cmd);
}
