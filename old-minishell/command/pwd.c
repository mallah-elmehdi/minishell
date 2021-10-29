#include "../minishell.h"


int ft_pwd(t_command *command)
{
	char pwd[1024];
	if (!getcwd(pwd, sizeof(pwd)))
		return (sys_error());
	printf("%s\n", pwd);
	return (SUCCESS);
}