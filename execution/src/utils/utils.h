/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <emallah@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:08:42 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 15:08:43 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int	valid_arg_export(char *arg);
int	valid_arg_unset(char *arg);
int	valid_input_export(t_ast *s_ast);
int	valid_input_unset(t_ast *s_ast);

#endif
