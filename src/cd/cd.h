#ifndef _CD_H
#define _CD_H

# include "../../variables.h"

int		cd(t_cmd *cmd);
char	*home_path(char **env);
char	*abs_path(const char *path, char **env);
char	*cd_path(const char *path, char **env);
int		update_env_export(t_env_export *env_export);

#endif