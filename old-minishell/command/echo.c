#include "../minishell.h"

int ft_echo(t_command *command, char **env)
{
	if (command->arg)
	{
		command->arg = ft_update_arg(command->arg, env);
		if (!command->arg)
			return (ERROR);
		write(1, command->arg, ft_strlen(command->arg));

	}
	if (!command->option)
		write(1, "\n", 1);
	return (SUCCESS);
}

char	*ft_update_arg(char *str, char **env)
{
	while (contains(str))
	{
		str = ft_update(str, env);
		if (!str)
			return (NULL);
	}
	return (str);
}

char	*ft_update(char *str, char **env)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\"' || str[i] == '\'')
			return (ft_qote_out(str, str[i]));
		if (str[i] == '$')
			return (ft_dollar(str, env));
		i++;
	}
	return (ft_slash(str));
}
