/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_to_normal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <emallah@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:20:49 by emallah           #+#    #+#             */
/*   Updated: 2021/11/15 16:20:49 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	redir_in_back_to_normal(t_redirect *redirect)
{
	close(redirect->fdin);
	if (dup2(redirect->stdin_fd, STDIN_FILENO) < 0)
		return (sys_error(NULL, NULL));
	close(redirect->stdin_fd);
	return (EXIT_SUCCESS);
}

int	redir_out_back_to_normal(t_redirect *redirect)
{
	close(redirect->fdout);
	if (dup2(redirect->stdout_fd, STDOUT_FILENO) < 0)
		return (sys_error(NULL, NULL));
	close(redirect->stdout_fd);
	return (EXIT_SUCCESS);
}
