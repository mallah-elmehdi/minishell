/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_string_from_table_of_args.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:16:02 by isghioua          #+#    #+#             */
/*   Updated: 2021/11/17 23:47:34 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	delete_string_from_table_of_args(t_ast **s_cmd,
		char **cap_content, char **new_str)
{
	int	size;

	size = get_size_of_table((*s_cmd)->argv);
	free(*new_str);
	*new_str = NULL;
	free(*cap_content);
	*cap_content = NULL;
	if (size > 1)
	{
		free((*s_cmd)->argv[size - 1]);
		(*s_cmd)->argv[size - 1] = NULL;
	}
	else
	{
		free((*s_cmd)->argv[0]);
		(*s_cmd)->argv[0] = NULL;
		free((*s_cmd)->argv[1]);
		(*s_cmd)->argv[1] = NULL;
		free((*s_cmd)->argv);
		(*s_cmd)->argv = NULL;
	}
}
