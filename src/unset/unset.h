#ifndef _UNSET_H
#define _UNSET_H

# include "../../variables.h"

int unset(t_cmd *cmd);
int remove_arg_env(t_env_export *env_export, char *arg);
int remove_arg_export(t_env_export *env_export, char *arg);
int remove_arg_env_export(t_env_export *env_export, char *arg);
int unset_env_export(t_cmd *cmd);

#endif