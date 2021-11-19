/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <emallah@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:32:02 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 13:32:04 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CD_H
# define CD_H

int		cd(t_ast *s_ast, t_env_export *env_export);
char	*cd_path(const char *arg, char **env);
char	*path_w_slash(const char *arg);
char	*home_path(char **env);
char	*abs_path(const char *arg);
char	*get_path(char *env_element);
int		update_env_export_old_pwd(t_env_export *env_export);
int		update_env_old_pwd(char **env, char *old_pwd);
int		update_export_old_pwd(char **export, char *old_pwd);
int		update_env_export_pwd(t_env_export *env_export);
int		update_env_pwd(char **env, char *new_pwd);
int		update_export_pwd(char **export, char *new_pwd);

#endif
