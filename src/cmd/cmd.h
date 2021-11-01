#ifndef _CMD_H
#define _CMD_H

# include "../../variables.h"

int             ft_cmds(t_cmd *cmds);
t_cmd           *init_cmds(t_env_export *env_export);
t_env_export    *init_env_export(const char **menv);

#endif