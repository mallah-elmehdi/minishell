#include "../minishell.h"

int	delim_length(char const *str, char delim)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (str[i])
	{
		if (str[i] == delim)
			length++;
		i++;
	}
	return (length);
}

char	**free_splited(char **splited, int i)
{
	while (i >= 0)
		free(splited[i--]);
	free(splited);
	return (NULL);
}

int	get_part(const char *str, char delim, int part)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (part == 0)
			return (i);
		if (str[i] == delim)
			part--;
		i++;
	}
	return (i);
}

char	*fill_str(const char *str, char delim, int part)
{
	char	*temp;
	int		j;
	int		k;

	k = 0;
	j = get_part(str, delim, part);
	temp = (char *)ft_calloc(sizeof(char), ft_strlen(str) + 1);
	if (temp == NULL)
		return (NULL);
	while (str[j])
	{
		if (str[j] == delim)
		{
			j++;
			break ;
		}
		temp[k++] = str[j++];
	}
	return (temp);
}

char	**ft_split(const char *str, char delim)
{
	char	**splited;
	int		i;

	i = 0;
	if (str == NULL)
		return (NULL);
	splited = (char **)ft_calloc(sizeof (char *), delim_length(str, delim) + 2);
	if (splited == NULL)
		return (NULL);
	while (i < delim_length(str, delim) + 1)
	{
		splited[i] = fill_str(str, delim, i);
		if (splited[i] == NULL)
			return (free_splited(splited, i - 1));
		i++;
	}
	return (splited);
}

char	*first_str(char *str, char delim)
{
	int 	i;
	char	*first;

	i = 0;
	first = (char *)ft_calloc(sizeof(char), ft_strlen(str) + 1);
	if (first == NULL)
		return (NULL);
	while (str[i])
	{
		if (str[i] == delim)
			break ;
		first[i] = str[i];
		i++;
	}
	return (first);
}

char	*second_str(char *str, char delim)
{
	int 	i;
	int 	j;
	char	*second;

	i = 0;
	j = 0;
	second = (char *)ft_calloc(sizeof(char), ft_strlen(str) + 1);
	if (second == NULL)
		return (NULL);
	while (str[i] && str[i] != delim)
		i++;
	i++;
	while (str[i])
		second[j++] = str[i++];
	return (second);
}

char	**ft_fsplit(const char *str, char delim)
{
	char	**splited;

	if (str == NULL)
		return (NULL);
	splited = (char **)ft_calloc(sizeof (char *), 3);
	if (splited == NULL)
		return (NULL);
	splited[0] = first_str((char *)str, delim);
	if (splited[0] == NULL)
		return (free_splited(splited, 0));
	splited[1] = second_str((char *)str, delim);
	if (splited[1] == NULL)
		return (free_splited(splited, 1));
	return (splited);
}