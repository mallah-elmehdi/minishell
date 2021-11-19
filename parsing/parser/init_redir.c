/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:43:11 by isghioua          #+#    #+#             */
/*   Updated: 2021/11/09 18:11:34 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*
 	#define MALLOC(x, y) (x = malloc(sizeof(*(x)) * (y))) // deferencement
	 https://gcc.gnu.org/onlinedocs/gcc-4.9.4/gfortran/SIZEOF.html
*/

t_redir	*init_redir(t_token *s_token, char *name_file)
{
	t_redir	*s_redir;

	s_redir = malloc(sizeof(t_redir));
	if (ft_strlen(s_token->value) == 1)
	{
		if (ft_strncmp(s_token->value, "<", 1) == 0)
			s_redir->e_type = INPUT_REDIR;
		else
			s_redir->e_type = OVERWRITE_REDIR;
	}
	else
	{
		if (ft_strncmp(s_token->value, "<<", 2) == 0)
			s_redir->e_type = HERE_DOC_REDIR;
		else
			s_redir->e_type = APPEND_REDIR;
	}
	s_redir->file_name = name_file;
	return (s_redir);
}
