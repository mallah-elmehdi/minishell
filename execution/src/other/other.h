/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:22:26 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 14:22:27 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTHER_H
# define OTHER_H

char	*try_all_paths(char **all_paths, char *cmd);
char	*get_cmd_path(char *cmd, char **env);
int		other(t_cmd *cmd);

#endif
