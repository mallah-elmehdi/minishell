#include "../../minishell.h"

char    *get_env_var_name(char *content, int i, int *j)
{
    char    *var;

	while (content[i] && (ft_isalnum(content[i])
        || ft_isdigit(content[i]) || content[i] == '_'))
	{
        i += 1;
		*j += 1;
	}
	var = ft_substr(content, (i - *j), *j);
    return (var);
}