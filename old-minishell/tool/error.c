#include "../minishell.h"

int error(t)
{
	printf("%s\n", strerror(errno));
	return (ERROR);
}