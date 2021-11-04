#ifndef MINISHELL_H
# define MINISHELL_H

# include "variables.h"

// parsing
# include "parsing/libft/libft.h"

# include "parsing/lexer/lexer.h"
# include "parsing/parser/tokens.h"

//execution
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

#endif