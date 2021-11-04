/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:37:42 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 13:37:44 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	execute_command(t_ast *s_ast, t_env_export *env_export)
{
	if (!s_ast)
		env(env_export->env);
	//int	i;

	//i = 0;
	//while (i < 1)
	//{
	//	if (ft_strbstr(s_ast[i]->, "cd"))
	//	{
	//		if (cd(&cmds[i]) == EXIT_FAILURE)
	//			return (sys_error(cmds[i].cmd, cmds[i].arg[0]));
	//	}
	//	else if (ft_strbstr(s_ast[i]->, "pwd"))
	//	{
	//		if (print_pwd() == EXIT_FAILURE)
	//			return (sys_error(cmds[i].cmd, cmds[i].arg[0]));
	//	}
	//	else if (ft_strbstr(s_ast[i]->, "export"))
	//	{
	//		if (ft_export(&cmds[i]) == EXIT_FAILURE)
	//			return (sys_error(cmds[i].cmd, cmds[i].arg[0]));
	//	}
	//	else if (ft_strbstr(s_ast[i]->, "env"))
	//	{
	//		if (env(cmds[i].env_export->env) == EXIT_FAILURE)
	//			return (sys_error(cmds[i].cmd, cmds[i].arg[0]));
	//	}
	//	else if (ft_strbstr(s_ast[i]->, "unset"))
	//	{
	//		if (unset(&cmds[i]) == EXIT_FAILURE)
	//			return (sys_error(cmds[i].cmd, cmds[i].arg[0]));
	//	}
	//	else if (ft_strbstr(s_ast[i]->, "echo"))
	//	{
	//		if (echo(&cmds[i]) == EXIT_FAILURE)
	//			return (sys_error(cmds[i].cmd, cmds[i].arg[0]));
	//	}
	//	else if (ft_strbstr(s_ast[i]->, "exit"))
	//	{
	//		if (ft_exit(&cmds[i]) == EXIT_FAILURE)
	//			return (sys_error(cmds[i].cmd, cmds[i].arg[0]));
	//	}
	//	else
	//	{
	//		if (other(&cmds[i]) == EXIT_FAILURE)
	//			return (sys_error(cmds[i].cmd, cmds[i].arg[0]));	
	//	}
	//	i++;
	//}
	return (EXIT_SUCCESS);
}
