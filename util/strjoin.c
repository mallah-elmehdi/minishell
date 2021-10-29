#include "../minishell.h"

size_t	lenth(const char *s, const char *s0)
{
	if (s == NULL && s0 != NULL)
		return (ft_strlen(s0) + 1);
	else if (s != NULL && s0 == NULL)
		return (ft_strlen(s) + 1);
	else
		return (ft_strlen(s) + ft_strlen(s0) + 1);
}

char	*ft_strjoin(const char *s, const char *s0)
{
	char	*p;
	size_t	j;

	if (s == NULL && s0 == NULL)
		return (NULL);
	j = lenth(s, s0);
	p = (char *)ft_calloc(sizeof(char), j);
	if (p == NULL)
		return (NULL);
	while (s != NULL && *s != '\0')
		*p++ = *(char *)s++;
	while (s0 != NULL && *s0 != '\0')
		*p++ = *(char *)s0++;
	return (&p[-j + 1]);
}

char	*ft_copy(char **temp, char *str, int length)
{
	int		i;
	int		j;
	int		k;
	char	*output;

	output = (char *)ft_calloc(sizeof(char), length);
	if (output == NULL)
		return (NULL);
	i = 0;
	j = ft_strcpy(output, str);
	while (temp[i])
	{
		k = 0;
		while (temp[i][k])
		{
			if (temp[i][k] != '"' && temp[i][k] != '\'' )
				output[j++] = temp[i][k];
			k++;
		}
		if (i == 0)
			output[j++] = '=';
		output[j++] = '"';
		i++;
	}
	return (output);
}

char *ft_strjoin_w_quote(char *str1, char *str2)
{
	int		length;
	char	*output;
	char	**temp;

	length = ft_strlen(str1) + ft_strlen(str2) + 3;
	temp = ft_fsplit(str2, '=');
	if (temp == NULL)
		return (NULL);
	output = ft_copy(temp, str1, length);
	if (output == NULL)
	{
		free_double(temp);
		return (NULL);
	}
	free_double(temp);
	return (output);
}