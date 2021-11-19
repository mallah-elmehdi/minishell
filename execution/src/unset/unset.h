/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <emallah@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:01:51 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 15:01:52 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNSET_H
# define UNSET_H

int	ft_unset(t_ast *s_ast, t_env_export *env_export);
int	delete_export_elements2(char **export, char *temp);
int	delete_export_elements(char **export, char *temp);
int	unset_env_export(t_ast *s_ast, t_env_export *env_export);
int	remove_arg_env(t_env_export *env_export, char *arg);
int	remove_arg_export(t_env_export *env_export, char *arg);
int	remove_arg_env_export(t_env_export *env_export, char *arg);
int	new_export_env(t_env_export *env_export);
int	new_export(t_env_export *env_export);
int	new_env(t_env_export *env_export);

#endif
