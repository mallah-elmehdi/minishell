#ifndef _CMD_H
#define _CMD_H

# include "../../variables.h"

int             ft_cmds(t_cmd *cmds);
t_cmd           *init_cmds(t_env_export *env_export, t_last_status *last_status);
t_env_export    *init_env_export(const char **menv);
t_last_status	*init_last_status(void);

#endif