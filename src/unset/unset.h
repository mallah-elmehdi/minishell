/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:01:51 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 15:01:52 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNSET_H
# define UNSET_H

int	unset(t_cmd *cmd);
int	remove_arg_env(t_env_export *env_export, char *arg);
int	remove_arg_export(t_env_export *env_export, char *arg);
int	remove_arg_env_export(t_env_export *env_export, char *arg);
int	unset_env_export(t_cmd *cmd);
int	delete_export_elements(char **export, char *temp);

#endif
