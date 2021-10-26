#include "../minishell.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	int				i;
	unsigned char	*p0;
	unsigned char	*p1;

	p0 = (unsigned char*)str1;
	p1 = (unsigned char*)str2;
	i = 0;
	while (i <= ft_strlen(str1) && i <= ft_strlen(str2))
	{
		if (p0[i] != p1[i])
			return (p0[i] - p1[i]);
		i++;
	}
	return (0);
}