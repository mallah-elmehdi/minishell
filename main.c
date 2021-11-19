/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 22:59:25 by emallah           #+#    #+#             */
/*   Updated: 2021/11/17 22:01:39 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	main_exec(t_lexer *s_lexer, t_env_export *env_export)
{
	char	*cmdline_buf;

	g_global.global = 0;
	g_global.here_doc = 0;
	g_global.here_doc_exit = 0;
	cmdline_buf = readline("$ ");
	if (!cmdline_buf)
	{
		printf("exit\n");
		clear_history();
		exit(g_global.status);
	}
	if (cmdline_buf[0] != '\0')
	{
		add_history(cmdline_buf);
		s_lexer = init_lexer(cmdline_buf);
		parse_and_execute(s_lexer, env_export);
	}
	else
		free(cmdline_buf);
}

int	main(int argc, char **argv, char **arge)
{
	t_env_export	*env_export;
	t_lexer			*s_lexer;

	(void)argc;
	(void)*argv;
	s_lexer = NULL;
	signal(SIGINT, catch_int);
	signal(SIGQUIT, catch_quit);
	env_export = init_env_export((const char **)arge);
	while (1)
		main_exec(s_lexer, env_export);
	clear_history();
	return (0);
}
