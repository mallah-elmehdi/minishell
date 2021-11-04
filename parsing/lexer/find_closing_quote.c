/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_closing_quote.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:33:25 by isghioua          #+#    #+#             */
/*   Updated: 2021/10/13 18:10:09 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	find_closing_quote(char	*str, int index, char char_quote)
{
	int	count;

	index += 1;
	count = 0;
	while (str[index] != '\0')
	{
		if (str[index] != char_quote)
		{
			count++;
			index++;
		}
		else
			break ;
	}
	if (str[index] == '\0')
		return (0);
	return (count);
}
