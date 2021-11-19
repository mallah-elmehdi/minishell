/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <emallah@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:21:02 by emallah           #+#    #+#             */
/*   Updated: 2021/11/15 16:21:04 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_redir(t_ast *s_ast, t_env_export *env_export, char *heredoc_file_name)
{
	t_redirect	*redirect;

	redirect = init_redirect(s_ast, heredoc_file_name);
	if (redirect == NULL)
		return (ERROR);
	if (redirect->fdin != 0)
		simple_redir_in(redirect, s_ast);
	if (redirect->fdout != 0)
		simple_redir_out(redirect, s_ast);
	ft_cmd(s_ast, env_export);
	if (redirect->fdin != 0)
		redir_in_back_to_normal(redirect);
	if (redirect->fdout != 0)
		redir_out_back_to_normal(redirect);
	free(redirect);
	free(heredoc_file_name);
	return (EXIT_SUCCESS);
}
