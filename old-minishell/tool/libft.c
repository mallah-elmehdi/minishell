#include "../minishell.h"

char	*ft_calloc(int a, int b)
{
	int		i;
	char	*p;

	i = 0;
	p = (char *)malloc(a * b);
	if (!p)
		return (NULL);
	while (i < a * b)
		p[i++] = 0;
	return (p);
}

int ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (str1[i] - str2[i]);
}

char	*ft_strdup(char *str)
{
	int	i;
	char	*p;

	i = 0;
	p = (char*)ft_calloc(sizeof(char), ft_strlen(str) + 1);
	if (!p)
		return (NULL);
	while (str[i])
	{
		p[i] = str[i];
		i++;
	}
	return (p);
}

int	ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (SUCCESS);
}