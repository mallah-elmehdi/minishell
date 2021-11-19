/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 02:47:39 by emallah           #+#    #+#             */
/*   Updated: 2021/11/18 02:47:40 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	here_doc_int_child(int sig)
{
	(void)sig;
	exit(1);
}

void	catch_int(int sig)
{
	(void)sig;
	if (g_global.here_doc == 0)
	{
		if (g_global.global == 0)
		{
			printf("\n");
			rl_replace_line("", 0);
			rl_on_new_line();
			rl_redisplay();
			g_global.status = 1;
		}
		else if (g_global.global == 1 || g_global.global == 2)
			printf("\n");
	}
	else
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	catch_quit(int sig)
{
	if (g_global.here_doc == 0)
	{
		(void)sig;
		if (g_global.global == 0)
		{
			rl_on_new_line();
			rl_redisplay();
		}
		else if (g_global.global == 1)
			printf("Quit: 3\n");
	}
}
