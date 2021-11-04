#include "../../minishell.h"

int	**ft_pipe(int pipe_length)
{
	int	i;
	int	**fd;

	i = 0;
	fd = (int **)ft_fcalloc(sizeof(int *), pipe_length);
	if (fd == NULL)
		return (NULL);
	while (i < pipe_length)
	{
		fd[i] = (int *)ft_fcalloc(sizeof(int), 2);
		if (fd[i] == NULL || pipe(fd[i]) == ERROR)
		{
			free_double(fd);
			return (NULL);
		}
		i++;
	}
	return (fd);
}