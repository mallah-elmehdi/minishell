#ifndef VARIABLES_H
# define VARIABLES_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>

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
	char			**opt;
	t_env_export	*env_export;
	t_last_status	*status;
}	t_cmd;

#endif