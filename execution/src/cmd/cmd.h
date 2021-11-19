/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <emallah@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:37:36 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 13:37:39 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

int	execute_command(t_ast *s_ast, t_env_export *env_export);
int	ft_cmd_phase_1(t_ast *s_ast, t_env_export *env_export);
int	ft_cmd_phase_2(t_ast *s_ast, t_env_export *env_export);
int	ft_cmd_phase_3(t_ast *s_ast, t_env_export *env_export);
int	ft_cmd_phase_4(t_ast *s_ast, t_env_export *env_export);
int	ft_cmd(t_ast *s_ast, t_env_export *env_export);

#endif
