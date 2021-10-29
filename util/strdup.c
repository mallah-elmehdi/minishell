#include "../minishell.h"

char	*ft_strdup(const char *str)
{
	int	i;
	int	slen;
	char	*p;

	slen = ft_strlen((str)) + 1;
	p = (char *)ft_calloc(sizeof(char), slen);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (((char *)str)[i] != '\0')
	{
		p[i] = ((char *)str)[i];
		i++;
	}
	return (p);
}

char	*ft_strdup_wout_quote(const char *str)
{
	int	i;
	int	j;
	int	slen;
	char	*p;

	slen = ft_strlen((str)) + 1;
	p = (char *)ft_calloc(sizeof(char), slen);
	if (p == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (((char *)str)[i] != '\0')
	{
		if (((char *)str)[i] != '\'' && ((char *)str)[i] != '"')
			p[j++] = ((char *)str)[i];
		i++;
	}
	return (p);
}