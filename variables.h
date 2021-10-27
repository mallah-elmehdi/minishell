#ifndef _VARIABLES_H
#define _VARIABLES_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>

typedef struct s_env_export 
{
	char	**export;
	char	**env;
}	t_env_export;

typedef struct s_cmd 
{
	char			*cmd;
	char			**arg;
	char			**opt;
	t_env_export	*env_export;
}	t_cmd;

#endif