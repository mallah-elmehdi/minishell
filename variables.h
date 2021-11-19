/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 22:50:53 by emallah           #+#    #+#             */
/*   Updated: 2021/11/17 22:04:20 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLES_H
# define VARIABLES_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>

# include <readline/readline.h>
# include <readline/history.h>

# include <signal.h>

# include <termios.h>

# include <curses.h>
# include <term.h>

# define ERROR -1

typedef struct s_global
{
	int	status;
	int	global;
	int	here_doc;
	int	here_doc_exit;
}	t_global;

t_global	g_global;

typedef struct s_redirect
{
	int	fdout;
	int	fdin;
	int	stdout_fd;
	int	stdin_fd;
	int	here_doc_length;
}	t_redirect;

typedef struct s_env_export
{
	char	**export;
	char	**env;
}	t_env_export;

typedef struct s_last_status
{
	int	last_status;
}	t_last_status;

typedef struct LEXER_STRUCT
{
	char			*content;
	unsigned int	index;
	char			current_char;
}		t_lexer;

typedef struct token_struct
{
	enum
	{
		TOKEN_STRING,
		TOKEN_HERE_DOC_INPUT,
		TOKEN_REDIRECT_FILE_INPUT,
		TOKEN_APPEND_OUTPUT,
		TOKEN_OVERWRITE_OUTPUT,
		TOKEN_PIPE,
		TOKEN_EOF,
	} e_type;
	char	*value;
}	t_token;

typedef struct redir_struct
{
	enum
	{
		INPUT_REDIR,
		HERE_DOC_REDIR,
		OVERWRITE_REDIR,
		APPEND_REDIR,
	} e_type;
	char	*file_name;
}	t_redir;

typedef struct ast_struct
{
	enum
	{
		AST_SIMPLE_COMMAND,
		AST_PIPLINE_COMMAND,
	} e_type;
	char				**argv;
	t_redir				**redir;
	int					nbr_pipes;
	struct ast_struct	*child_cmd;
}	t_ast;

typedef struct s_cmd_pipe
{
	char	**heredoc_files_names;
	char	**heredoc_files_names_free;
	int		*pid_child;
	int		nbr_pipe;
	int		pipe_fd[2];
	int		fdin;

}	t_cmd_pipe;

#endif
