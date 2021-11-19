/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_string_to_table_of_args.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:15:59 by isghioua          #+#    #+#             */
/*   Updated: 2021/11/12 19:09:13 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	add_string_to_table_of_args(char **cap_content, t_ast **s_cmd)
{
	int		size;
	char	*new_str;

	size = get_size_of_table((*s_cmd)->argv);
	new_str = ft_strjoin((*s_cmd)->argv[size - 1], *cap_content);
	free((*s_cmd)->argv[size - 1]);
	(*s_cmd)->argv[size - 1] = NULL;
	(*s_cmd)->argv[size - 1] = new_str;
	free(*cap_content);
	*cap_content = NULL;
}
