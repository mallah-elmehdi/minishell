/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:37:36 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 13:37:39 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

# include "../../variables.h"

int             ft_cmds(t_cmd *cmds);
t_cmd           *init_cmds(t_env_export *env_export, t_last_status *last_status);
t_env_export    *init_env_export(const char **menv);
t_last_status	*init_last_status(void);

#endif
