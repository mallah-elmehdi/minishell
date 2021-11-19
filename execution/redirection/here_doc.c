/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:20:52 by emallah           #+#    #+#             */
/*   Updated: 2021/11/17 04:23:14 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	child_here_doc(t_env_export *env_export, char *limiter, int fd)
{
	char	*limiter_w_efl;
	char	*line;

	limiter_w_efl = ft_fstrjoin(limiter, "\n");
	signal(SIGINT, here_doc_int_child);
	while (1)
	{
		write(STDOUT_FILENO, "> ", 2);
		line = mini_gnl();
		if (ft_strchr(line, '$'))
			expand_line(env_export, &line);
		if (ft_strcstr(limiter_w_efl, line) || ft_fstrlen(line) == 0)
		{
			free(limiter_w_efl);
			free(line);
			break ;
		}
		write(fd, line, ft_fstrlen(line));
		free(line);
	}
	close(fd);
	exit(0);
}

int	here_doc(t_env_export *env_export, char *limiter, char *heredoc_file_name)
{
	pid_t	pid;
	int		fd;
	int		status;

	fd = open(heredoc_file_name, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		return (sys_error(NULL, NULL));
	pid = fork();
	if (pid == 0)
		child_here_doc(env_export, limiter, fd);
	waitpid(pid, &status, 0);
	if (WEXITSTATUS(status) != 0)
		g_global.here_doc_exit = 1;
	close(fd);
	return (EXIT_SUCCESS);
}

int	cmd_has_here_doc(t_ast *s_ast)
{
	int	i;

	i = 0;
	if (s_ast->redir == NULL)
		return (EXIT_FAILURE);
	while (s_ast->redir[i] != NULL)
	{
		if (s_ast->redir[i]->e_type == HERE_DOC_REDIR)
			return (EXIT_SUCCESS);
		i++;
	}
	return (EXIT_FAILURE);
}

int	nbr_here_doc(t_ast *s_ast)
{
	int		length;
	int		i;

	i = 0;
	length = 0;
	while (s_ast->redir[i])
	{
		if (s_ast->redir[i]->e_type == HERE_DOC_REDIR)
			length++;
		i++;
	}
	if (length == 0)
		return (-1);
	return (length);
}

char	*mini_gnl(void)
{
	char	*buf;
	char	*temp;
	char	*line;

	line = (char *)ft_calloc(sizeof(char), 2);
	buf = (char *)ft_calloc(sizeof(char), 2);
	while (read(STDIN_FILENO, buf, 1))
	{
		temp = ft_fstrjoin(line, buf);
		free(line);
		line = ft_fstrdup(temp);
		free(temp);
		if (buf[0] == '\n')
			break ;
	}
	free(buf);
	return (line);
}
