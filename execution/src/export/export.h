/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <emallah@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:22:26 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 14:22:27 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_H
# define EXPORT_H

int		ft_export(t_ast *s_ast, t_env_export *env_export);
void	print_export(char **export);
int		add_env_export(t_env_export *env_export, char **temp);
int		add_export(t_env_export *env_export, char *arg);
int		push_arg_export(t_env_export *env_export, char *arg);
int		add_to_export(t_ast *s_ast, t_env_export *env_export);
int		env_exist(char **env, char *var_name);
int		env_exist_try_1(char **env, char *var_name_w_equal);
int		update_arg_env(char **env, char *var_name, char *var_value);
int		add_arg_env(t_env_export *env_export, char *var_name, char *var_value);
char	**refill_env(char **env);
int		add_arg_export(t_env_export *env_export,
			char *var_name, char *var_value);
char	*added_arg(char *var_name, char *var_value);
char	**refill_export(char **export);
int		update_arg_export(char **export, char *var_name, char *var_value);
char	*update_arg_export_help(char *temp, char *var_value);
int		export_exist(char **export, char *var_name);
int		export_exist_try_1(char **export, char *var_name_w_equal);
int		export_exist_try_2(char **export, char *var_name_w_equal);

#endif
