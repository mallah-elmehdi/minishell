#include "../minishell.h"

void	*ft_calloc(int a, int b)
{
	int	i;
	void	*p;

	i = 0;
	p = malloc(a * b);
	if (!p)
		return (NULL);
	while (i < (a * b))
	{
		((unsigned char *)p)[i] = '\0';
		i++;
	}
	return (p);
}