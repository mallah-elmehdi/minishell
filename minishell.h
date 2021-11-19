/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 22:50:32 by emallah           #+#    #+#             */
/*   Updated: 2021/11/16 20:22:44 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "variables.h"

# include "parsing/libft/libft.h"

# include "parsing/lexer/lexer.h"
# include "parsing/parser/parser.h"

# include "execution/util/util.h"
# include "execution/src/cmd/cmd.h"
# include "execution/src/cd/cd.h"
# include "execution/src/env/env.h"
# include "execution/src/export/export.h"
# include "execution/src/pwd/pwd.h"
# include "execution/src/unset/unset.h"
# include "execution/src/utils/utils.h"
# include "execution/src/echo/echo.h"
# include "execution/src/exit/exit.h"
# include "execution/src/other/other.h"
# include "execution/init/init.h"
# include "execution/redirection/redirection.h"
# include "execution/pipe/pipe.h"
# include "execution/signal/signal.h"

void	main_exec(t_lexer *s_lexer, t_env_export *env_export);

#endif
