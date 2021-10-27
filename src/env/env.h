#ifndef _ENV_H
#define _ENV_H

# include "../../variables.h"

int		env(char **env);
char	**init_env(const char **menv);
int		update_env(char **env);
int		update_env_old_pwd(char **env);
int		update_env_pwd(char **env);

#endif