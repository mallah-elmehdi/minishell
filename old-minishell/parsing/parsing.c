#include "../minishell.h"

int	ft_parsing(char *line, char **env)
{
	t_command *commands;
	
	int i = 0;
	commands = ft_get_the_struct(line);
	if (!commands)
		return (ERROR);
	while (i < 1)
	{
		if (ft_execution(&commands[i], env))
			return (ERROR);
		i++;
	}
	free(commands);
	return (SUCCESS);
}

t_command	*ft_get_the_struct(char *command)
{
	t_command *commands;

	commands = (t_command *)malloc(sizeof(t_command) * 1);
	if (!commands)	
		return (NULL);
	commands[0].command = ft_strdup("echo");
	commands[0].arg = ft_strdup("$_");
	commands[0].option = NULL;
	// commands[0].option = ft_strdup("");
	return (commands);
}