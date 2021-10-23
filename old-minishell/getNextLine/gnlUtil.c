#include "../minishell.h"

int		ft_realloc(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_strdup(str);
	free(str);
	str = (char *)ft_calloc(sizeof(char), ft_strlen(temp) + 1001);
	if (!str)
		return (ERROR);
	ft_strcpy(str, temp);
	free(temp);
	return (0);
}

int check_line(char *temp, char *line)
{
	int i;

	i = 0;
	while (temp[i])
	{
		if (temp[i] == '\n')
		{
			line[i] = 0;
			return (SUCCESS);
		}
		line[i] = temp[i];
		i++;
	}
	return (ERROR);
}