/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:46:59 by isghioua          #+#    #+#             */
/*   Updated: 2021/11/09 15:47:17 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token	*init_token(int type, char *value)
{
	t_token	*s_token;

	s_token = malloc(sizeof(t_token));
	s_token->e_type = type;
	s_token->value = value;
	return (s_token);
}
