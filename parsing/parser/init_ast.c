/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:43:07 by isghioua          #+#    #+#             */
/*   Updated: 2021/11/09 18:11:28 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/* To test if memset work fine:
 * 	printf("%p\n", s_cmd->str);  ==> 0x0
 *  printf("%p\n", s_cmd->argv); ==> 0x0
 *  printf("%d\n", s_cmd->integer); ==> 0
*/

t_ast	*init_ast(int type)
{
	t_ast	*s_cmd;

	s_cmd = malloc(sizeof(t_ast));
	ft_memset(s_cmd, '\0', sizeof(t_ast));
	s_cmd->e_type = type;
	return (s_cmd);
}
