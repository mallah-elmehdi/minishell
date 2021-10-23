#include "../minishell.h"

int ft_execution(t_command *command, char **env)
{

	if (!ft_strcmp(command->command, "echo"))
		return (ft_echo(command, env));
	// if (!ft_strcmp(command->command, "env"))
	// 	return (ft_env(command, env));
	// if (!ft_strcmp(command->command, "pwd"))
	// 	return (ft_pwd(command));
	// if (!ft_strcmp(command->command, "exit"))
	// 	return (ft_exit(command));
	// if (!ft_strcmp(command->command, "export"))
	// 	return (ft_export(command, env));
	return (SUCCESS);
}