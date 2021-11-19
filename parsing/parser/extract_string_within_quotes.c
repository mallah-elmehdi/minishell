/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_string_within_quotes.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:28:50 by isghioua          #+#    #+#             */
/*   Updated: 2021/11/05 21:31:57 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*extract_string_within_quotes(char *content, int *index,
		char char_quote)
{
	char	*new_content;
	int		length;

	length = find_closing_quote(content, *index, char_quote);
	if (length == -1)
		new_content = ft_substr(content, *index, 1);
	else if (length == 0)
	{
		new_content = ft_strdup("");
		*index += 1;
	}
	else
	{
		*index += 1;
		new_content = ft_substr(content, *index, length);
		*index += length;
	}
	return (new_content);
}
