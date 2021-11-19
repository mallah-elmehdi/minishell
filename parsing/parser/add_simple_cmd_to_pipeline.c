/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_simple_cmd_to_pipeline.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:15:55 by isghioua          #+#    #+#             */
/*   Updated: 2021/11/09 17:36:34 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	add_simple_cmd_to_pipeline(t_ast *s_parent, t_ast *s_child)
{
	t_ast	*s_next_child;

	if (!s_parent->child_cmd)
		s_parent->child_cmd = s_child;
	else
	{
		s_parent->nbr_pipes += 1;
		s_next_child = s_parent->child_cmd;
		while (s_next_child->child_cmd)
			s_next_child = s_next_child->child_cmd;
		s_next_child->child_cmd = s_child;
	}
}
