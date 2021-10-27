#ifndef _EXPORT_H
#define _EXPORT_H

# include "../../variables.h"

int		ft_export(t_cmd *cmd);
int		add_to_export(t_cmd *cmd);
int		print_export(char **_export);
int		*init_sort_table(const char **menv);
int		*sort_table(const char **menv);
char	**init_export(const char **menv);
int		update_export(char **_export);
int		update_export_old_pwd(char **_export);
int		update_export_pwd(char **_export);
int		export_exist(char **_export, char *variable_name);
int 	update_arg_export(char **_export, char *arg, char *variable_name);
int		add_export_w_equal(char **_export, char *arg);

#endif