#include "../../minishell.h"

int	*init_sort_table(const char **menv)
{
	int i;
	int	*sorted;

	i = 0;
	sorted = (int *)ft_calloc(sizeof(int), ft_strlen_double(menv));
	if (sorted == NULL)
		return (NULL);	
	while (menv[i])
	{
		sorted[i] = i;
		i++;
	}
	return (sorted);
}

int	*sort_table(const char **menv)
{
	int i;
	int temp;
	int	*sorted;

	i = 0;
	sorted = init_sort_table(menv);
	if (sorted == NULL)
		return (NULL);
	while (i < ft_strlen_double(menv) - 1)
	{
		if (ft_strcmp(menv[sorted[i]], menv[sorted[i + 1]]) > 0)
		{
			temp = sorted[i];
			sorted[i] = sorted[i + 1];
			sorted[i + 1] = temp;
			i = -1;
		}
		i++;
	}
	return (sorted);
}


char	**init_export(const char **menv)
{
	int		i;
	int		*sorted;
	char	**export;

	i = 0;
	sorted = sort_table(menv);
	if (sorted == NULL)
		return (NULL);
	export = (char **)ft_calloc(sizeof(char *), ft_strlen_double(menv) + 1);
	if (export == NULL)
	{
		free(sorted);
		return (NULL);
	}
	while (menv[i])
	{
		export[i] = ft_strjoin("declare -x ", menv[sorted[i]]);
		if (export[i] == NULL)
		{
			free_double(export);
			return (NULL);
		}
		i++;
	}
	return (export);
}

int	update_export(char *path, char **export)
{
	char	*old_pwd;
	int		i;

	old_pwd = get_old_pwd(export);

	i = 0;
	if (old_pwd == NULL)
		return (EXIT_FAILURE);
	while (export[i])
	{
		if (ft_strnstr(export[i], "OLDPWD", 6))
		{
			free(export[i]);
			export[i] = ft_strjoin("declare -x OLDPWD=", old_pwd);
			free(old_pwd);
			if (export[i] == NULL)
				return (EXIT_FAILURE);
		}
		if (ft_strnstr(export[i], "PWD", 3))
		{
			free(export[i]);
			export[i] = ft_strjoin("declare -x PWD=", path);
			if (export[i] == NULL)
				return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
