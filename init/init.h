#ifndef INIT_H
# define INIT_H

t_last_status	*init_last_status(void);
t_env_export	*init_env_export(const char **menv);
t_cmd			*init_cmds(t_env_export *env_export, t_last_status *last_status);
t_cmd			*init(char **menv);

#endif
