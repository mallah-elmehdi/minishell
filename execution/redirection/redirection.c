#include "../../minishell.h"

void	redirection(int fdin, int fdout)
{
	dup2(fdin, STDIN_FILENO);
	dup2(fdout, STDOUT_FILENO);
}