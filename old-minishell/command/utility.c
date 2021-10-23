#include "../minishell.h"

char	*ft_strfcpy(char *str, char c)
{
	int i;
	char *temp;

	i = 0;
	temp = (char *)ft_calloc(sizeof(char), ft_strlen(str) + 1);
	if (!temp)
		return (NULL);
	while (str[i])
	{
		if (str[i] == c)
			return (temp);
		temp[i] = str[i];
		i++;
	}
	return (temp);
}

char	*ft_strbcpy(char *str, char c)
{
	int i;
	int j;
	char *temp;

	i = ft_start(str, c) + 1;
	j = 0;
	temp = (char *)ft_calloc(sizeof(char), ft_strlen(str) + 1);
	if (!temp)
		return (NULL);
	while (str[i])
		temp[j++] = str[i++];
	return (temp);
}

char	*ft_strlcpy(char *str, char c)
{
	int i;
	int j;
	char *temp;

	i = ft_stop(str, c) + 1;
	j = 0;
	temp = (char *)ft_calloc(sizeof(char), ft_strlen(str) + 1);
	if (!temp)
		return (NULL);
	while (str[i])
		temp[j++] = str[i++];
	return (temp);
}

char	*ft_strmcpy(char *str, char c)
{
	int i;
	int j;
	int stop;
	char *temp;

	i = ft_start(str, c) + 1;
	stop = ft_stop(str, c);
	j = 0;
	temp = (char *)ft_calloc(sizeof(char), ft_strlen(str) + 1);
	if (!temp)
		return (NULL);
	while (i < stop)
		temp[j++] = str[i++];
	return (temp);
}

void	free_v2(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
}