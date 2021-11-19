/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emallah <emallah@1337.ma>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 17:27:56 by emallah           #+#    #+#             */
/*   Updated: 2021/11/15 17:27:58 by emallah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPE_H
# define PIPE_H

int			ft_pipe(t_ast *s_ast, t_env_export *env_export);
t_cmd_pipe	*init_cmd_pipe(t_ast *s_ast, t_env_export *env_export);

int			exec_here_doc_all_cmd(t_ast *s_ast, t_env_export *env_export,
				char **heredoc_files_names);
char		*here_doc_file_name_gen(int j);
void		heredoc_file_name_fill(t_ast *s_ast, char **heredoc_files_names);
char		**heredoc_files_names_all_cmd(t_ast *s_ast);
int			nbr_here_doc_all_cmd(t_ast *s_ast);

void		exec_child_cmd(t_ast *the_cmd, t_env_export *env_export,
				t_cmd_pipe *cmd_pipe, int i);
void		redirect_child_cmd(t_cmd_pipe *cmd_pipe, int i);
int			ft_cmd_pipe(t_ast *s_ast, t_env_export *env_export,
				char *heredoc_file_name);
void		wait_for_child(t_cmd_pipe *cmd_pipe);

#endif
