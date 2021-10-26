#include "../minishell.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	ft_strlen_double(const char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}