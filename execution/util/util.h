/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:17:22 by emallah           #+#    #+#             */
/*   Updated: 2021/11/02 13:17:26 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void	*ft_fcalloc(int a, int b);
int		sys_error(char *cmd, char *arg);
int		prg_error(char *cmd, char *arg, char *msg);
int		prg_error_no_exit(char *cmd, char *msg);
void	free_double(char **double_ptr);
char	**free_splited(char **splited, int i);
char	*fill_str(const char *str, char delim, int part);
char	**ft_split(const char *str, char delim);
int		ft_strcmp(const char *str1, const char *str2);
char	*ft_strdup(const char *str);
size_t	lenth(const char *s, const char *s0);
char	*ft_strjoin(const char *s, const char *s0);
char	*ft_strjoin_w_quote(char *str1, char *str2);
int		ft_fstrlen(const char *str);
int		ft_fstrlen_double(const char **str);
char	*ft_fstrnstr(const char *str1, const char *str2, int n);
int		ft_strcpy(char *dest, char *src);
char	*ft_strdup_wout_quote(const char *str);
char	*ft_strbstr(const char *str1, const char *str2);
char	*first_str(char *str, char delim);
char	*second_str(char *str, char delim);
char	**ft_fsplit(const char *str, char delim);
char	*ft_copy(char **temp, char *str, int length);
int		ft_isalpha(int a);
int		ft_isalnum(int a);
int		ft_isdigit(int a);
long	ft_fatoi(const char *str);

#endif
