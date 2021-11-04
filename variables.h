#ifndef VARIABLES_H
# define VARIABLES_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>

# include <readline/readline.h>
# include <readline/history.h>

# include <signal.h>

# include <termios.h>

# include <curses.h>
# include <term.h>

# define ERROR -1

typedef struct s_env_export 
{
	char	**export;
	char	**env;
}	t_env_export;

typedef struct s_last_status 
{
	int	last_status;
}	t_last_status;

typedef struct s_cmd 
{
	char			*cmd;
	char			**arg;
	t_env_export	*env_export;
	t_last_status	*status;
}	t_cmd;

typedef struct	LEXER_STRUCT
{
	char		*content;
	unsigned int	index;
	char		current_char;
}		t_lexer;


typedef struct	token_struct
{
	enum
	{
		TOKEN_STRING,
		TOKEN_HERE_DOC_INPUT,
		TOKEN_REDIRECT_FILE_INPUT,
		TOKEN_APPEND_OUTPUT,
		TOKEN_OVERWRITE_OUTPUT,
		TOKEN_PIPE,
		//TOKEN_AND,
		//TOKEN_OR,
		//TOKEN_STAR,
		TOKEN_EOF,
	} type;

	char				*value; 
}						t_token;

typedef struct	redir_struct
{
	enum
	{
		INPUT_REDIR,
		HERE_DOC_REDIR,
		OVERWRITE_REDIR,
		TRUNC_REDIR,
	}	type;
	char	*file_name;
}			t_redir;

typedef struct	ast_struct
{
	enum
	{
		AST_SIMPLE_COMMAND,
		AST_PIPLINE_COMMAND,
	}	type;
	char				**argv;
	char				**redir;
	int					nbr_pipes;
	struct ast_struct	*child_cmd;
}						t_ast;

#endif