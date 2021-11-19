/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <emallah@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:21:07 by emallah           #+#    #+#             */
/*   Updated: 2021/11/15 16:21:08 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	simple_redir_in(t_redirect *redirect, t_ast *s_ast)
{
	if (s_ast->argv == NULL || ft_strcstr(s_ast->argv[0], "exit") == NULL)
	{
		if (dup2(redirect->fdin, STDIN_FILENO) < 0)
			return (sys_error(NULL, NULL));
	}
	return (EXIT_SUCCESS);
}

int	simple_redir_out(t_redirect *redirect, t_ast *s_ast)
{
	if (s_ast->argv == NULL || ft_strcstr(s_ast->argv[0], "exit") == NULL)
	{
		if (dup2(redirect->fdout, STDOUT_FILENO) < 0)
			return (sys_error(NULL, NULL));
	}
	return (EXIT_SUCCESS);
}
