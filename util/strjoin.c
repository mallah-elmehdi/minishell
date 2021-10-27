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

char *ft_strjoin_w_quote(char *str)
{
	int		i;
	int		j;
	char	*output;

	output = (char *)ft_calloc(sizeof(char), ft_strlen(str) + 3);
	i = 0;
	j = 0;
	if (output == NULL)
		return (NULL);
	while (str[i])
	{
		if (str[i] != '"' && str[i] != '\'' )
		{
			output[j++] = str[i];
			if (str[i] == '=')
				output[j++] = '"';
		}
		i++;
	}
	output[j] = '"';
	return (output);
}