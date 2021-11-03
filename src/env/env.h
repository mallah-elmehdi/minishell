/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:45:01 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 13:45:03 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

int		env(char **env);
char	**init_env(const char **menv);
int		update_env(char **env);
int		update_env_old_pwd(char **env);
int		update_env_pwd(char **env);
int		update_arg_env(char **env, char *arg, char *variable_name);
int		add_arg_env(t_env_export *env_export, char *arg);

#endif
