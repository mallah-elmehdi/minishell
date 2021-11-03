/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:32:02 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 13:32:04 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CD_H
# define CD_H

int		cd(t_cmd *cmd);
char	*home_path(char **env);
char	*joined_abs_path(char *env, char *path_w_slash);
char	*abs_path(const char *path, char **env);
char	*cd_path(const char *path, char **env);
int		update_env_export(t_env_export *env_export);

#endif
