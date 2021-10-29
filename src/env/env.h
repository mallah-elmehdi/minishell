#ifndef _ENV_H
#define _ENV_H

# include "../../variables.h"

int		env(char **env);
char	**init_env(const char **menv);
int		update_env(char **env);
int		update_env_old_pwd(char **env);
int		update_env_pwd(char **env);
int		update_arg_env(char **env, char *arg, char *variable_name);
int		add_arg_env(t_env_export *env_export, char *arg);

#endif