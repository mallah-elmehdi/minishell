#ifndef MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_cmd 
{
	char *cmd;
	char **opt;
}	t_cmd;

#define MINISHELL_H
#endif