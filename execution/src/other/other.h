/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <emallah@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:43:53 by emallah           #+#    #+#             */
/*   Updated: 2021/11/15 15:43:55 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTHER_H
# define OTHER_H

int		other(t_ast *s_ast, t_env_export *env_export);
void	run_cmd(t_ast *s_ast, t_env_export *env_export);
int		str_includes(char *str, char c);
void	rum_cmd_abs_path(t_ast *s_ast, t_env_export *env_export);
void	rum_cmd_env_path(t_ast *s_ast, t_env_export *env_export);
char	*try_all_paths(char **all_paths, char *cmd);
char	*get_cmd_path(char *cmd, char **env);

#endif
