/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_and_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:32:40 by isghioua          #+#    #+#             */
/*   Updated: 2021/11/05 21:42:41 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_strjoin_and_free(char **cap_content, char **str)
{
	char	*new_str;

	new_str = ft_strjoin(*cap_content, *str);
	free(*cap_content);
	*cap_content = NULL;
	free(*str);
	*str = NULL;
	*cap_content = ft_strdup(new_str);
	free(new_str);
	new_str = NULL;
}
