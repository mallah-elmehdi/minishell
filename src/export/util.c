#include "../../minishell.h"

int export_exist(char **export, char *variable_name)
{
	int i;

	i = 0;
	while (export[i])
	{
		if (ft_strnstr(export[i], variable_name, ft_strlen(variable_name)))
			return (EXIT_SUCCESS);
		i++;
	}
	return (EXIT_FAILURE);
}

int update_arg_export(char **export, char *arg, char *variable_name)
{
	int i;

	i = 0;
	while (export[i])
	{
		if (ft_strnstr(export[i], variable_name, ft_strlen(variable_name)))
		{
			free(export[i]);
			export[i] = ft_strjoin_w_quote(arg);
			if (export[i] == NULL)
				return (EXIT_FAILURE);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	add_export_w_equal(char **export, char *arg)
{
	char **temp;
	char *variable_name;

	temp = ft_split(arg, "=");
	if (temp == NULL)
		return (EXIT_FAILURE);
	variable_name = ft_strjoin(temp[0], "=");
	free_double(temp);
	if (variable_name == NULL)
		return (EXIT_FAILURE);
	if (export_exist(export, variable_name) == EXIT_SUCCESS)
		update_arg_export(export, arg, variable_name);
	//else
		//add_arg_export(export, arg);
	free(variable_name);
	return (EXIT_SUCCESS);
}