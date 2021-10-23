#include "../minishell.h"

int contains(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\\' && str[i + 1])
			i++;
		else if (str[i] == '$'|| str[i] == '\'' || str[i] == '\"')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_slash(char *str)
{
	int i;
	int j;
	char *temp;

	i = 0;
	j = 0;
	temp = (char*)ft_calloc(sizeof(char), ft_strlen(str) + 1);
	if (!temp)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\\')
			i++;
		temp[j++] = str[i++];
	}
	free(str);
	return (temp);
}

char 	*ft_qote_out(char *str, char c)
{
	
	char	*temp;

	temp = ft_join_quote_out(str, c);
	if (!temp)
		return (NULL);
	free(str);
	return (temp);
}

char	*ft_join_quote_out(char *str, char c)
{
	char	**temp;
	char	*str_temp;
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	temp = ft_split_quote_out(str, c);
	str_temp = (char*)ft_calloc(sizeof(char), ft_strlen(str) + 1);
	if (!temp || !str_temp)
		return (NULL);
	while (temp[i])
	{
		j = 0;
		while (temp[i][j])
			str_temp[k++] = temp[i][j++];
		i++;
	}
	free_v2(temp);
	return (str_temp);
}
