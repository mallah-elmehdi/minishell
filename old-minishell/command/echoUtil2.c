#include "../minishell.h"

char	**ft_split_quote_out(char *str, char c)
{
	int i;
	int j;
	char	**temp;

	i = 0;
	j = 0;
	temp = (char **)ft_calloc_v2(sizeof(char*), 4);
	if (!temp)
		return (NULL);
	temp[0] = ft_strfcpy(str, c);
	temp[1] = ft_strmcpy(str, c);
	temp[2] = ft_strlcpy(str, c);
	if (temp[0] || temp[1] || temp[2])
		return (NULL);
	return (temp);
}

char	*ft_dollar(char *str, char **env)
{
	char	*strenv;
	char	*temp;

	strenv = ft_strenv(str, env);
	if (!strenv)
		return (NULL);
	temp = (char*)ft_calloc(sizeof(char), ft_strlen(str) + ft_strlen(strenv) + 1);
	if (!temp)
		return (NULL);
	free(str);
	return (temp);
}

void	ft_dollar_help(char *str, char *temp, char *strenv)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] != '$')
		temp[j++] = str[i++];
	i++;
	while (is_alpha(str[i]) || is_num(str[i]) || str[i] == '_')
		i++;
	while (strenv[k])
		temp[j++] = strenv[k++];
	while (str[i])
		temp[j++] = str[i++];
	free(str);
}

char	*ft_strenv(char *str, char **env)
{
	int i;
	char *strdollar;
	char **env_value_name;

	strdollar = ft_strdollar(str);
	if (!strdollar)
		return (NULL);
	while (env[i])
	{
		env_value_name = ft_split(env[i], '=');
		if (!env_value_name)
			return (NULL);
		if (!ft_strcmp(env_value_name[0], strdollar))
		{
			free(strdollar);
			return (env_value_name[1]);
		}
		free(env_value_name);
		i++;
	}
	free(strdollar);
	return (ft_strdup(""));
}

char	*ft_strdollar(char *str)
{
	int i;
	int j;
	char *env;

	i = 0;
	j = 0;
	env = (char*)ft_calloc(sizeof(char), ft_strlen(str) + 1);
	if (!env)
		return (NULL);
	while (str[i] != '$')
		i++;
	if (is_num(str[++i]))
		return (env);
	while (is_alpha(str[i]) || is_num(str[i]) || str[i] == '_')
		env[j++] = str[i++];
	return (env);
}