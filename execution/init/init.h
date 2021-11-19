/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <emallah@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 15:23:12 by emallah           #+#    #+#             */
/*   Updated: 2021/11/15 15:23:22 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

t_env_export	*init_env_export(const char **menv);

char			**init_export(const char **menv);
int				*sort_table(const char **menv);
int				*init_sort_table(const char **menv);
int				fill_export(const char **menv, char **export, int *sorted);
char			*export_arg(char *menv);

char			**init_env(const char **menv);

#endif
