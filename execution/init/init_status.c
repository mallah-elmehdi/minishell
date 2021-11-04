#include "../../minishell.h"

t_last_status	*init_last_status(void)
{
	t_last_status	*last_status;

	last_status = (t_last_status *)ft_fcalloc(sizeof(t_last_status), 2);
	if (last_status == NULL)
		return (NULL);
	last_status[0].last_status = 0;
	return (last_status);
}