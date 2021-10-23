#include "../minishell.h"

int	ft_stop(char *str, char c)
{
	int i;

	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (str[i] == c)
			return (i);
		i--;
	}
	return (0);
}

int	ft_start(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int	is_alpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	**ft_split(char *str, char c)
{
	char **temp;

	temp = (char **)ft_calloc_v2(sizeof(char*), 3);
	if (!temp)
		return (NULL);
	temp[0] = ft_strfcpy(str, '=');
	temp[1] = ft_strbcpy(str, '=');
	if (!temp[0] || !temp[1])
		return (NULL);
	return (temp);
}
