#include "../minishell.h"

char	*ft_strnstr(const char *str1, const char *str2, int n)
{
	int	i;
	int	a;

	i = 0;
	if (ft_strlen(str2) == 0)
		return ((char *)str1);
	while (str1[i] && i < n)
	{
		a = 0;
		while (str1[i + a] == str2[a] && (i + a) < n)
		{
			a++;
			if (str2[a] == '\0')
				return (&((char *)str1)[i]);
		}
		i++;
	}
	return (NULL);
}