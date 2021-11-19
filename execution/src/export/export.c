/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <emallah@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:22:30 by emallah           #+#    #+#             */
/*   Updated: 2021/11/15 15:39:03 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	ft_export(t_ast *s_ast, t_env_export *env_export)
{
	if (s_ast->argv[1] == NULL)
		print_export(env_export->export);
	else
		return (add_to_export(s_ast, env_export));
	return (EXIT_SUCCESS);
}
