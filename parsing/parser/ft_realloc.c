#include "../../minishell.h"

char	**ft_realloc_table(char **args, int i)
{
    char	**new_args;
	int		size;
	int 	j;

	j = 0;
	size = get_size_of_table(args);
	new_args = malloc(sizeof(char *) * (size + i + 1));
	while (j < size)
	{
		new_args[j] = args[j];
		j++;
	}
	free(args);
	args = NULL;
	return (new_args);
}
