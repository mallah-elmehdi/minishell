#include "../minishell.h"

int ft_strlen_v2(char **s)
{
	int		i;

	i = 0;
	while (s[i] != NULL)
		i++;
	return (i);
}

char	**ft_calloc_v2(int a, int b)
{
	int i;
	char	**p;

	i = 0;
	p = (char **)malloc(a * b);
	if (!p)
		return (NULL);
	while (i < b)
		p[i++] = NULL;
	return (p);
}

pid_t start_process(void)
{
	pid_t pid = fork();
	if (pid == ERROR)
		return (sys_error());
	wait(NULL);
	return (pid);
}

char	**ft_env_list(char **env)
{
	int	i;
	int	length;
	char	**str;

	i = 0;
	length = ft_strlen_v2(env);
	str = ft_calloc_v2(sizeof(char*), length + 1);
	if (!str)
		return(NULL);
	while (i < length)
	{
		str[i] = ft_strdup(env[i]);
		i++;
	}
	return (str);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int out;

	i = 0;
	out = 0;
	sign = 1;
	while (str[i])
	{
		if (str[i] == '-')
			sign = -1;
		else if (str[i] >= 48 && str[i] <= 57)
			out = (out * 10) + (str[i] - 48);
		i++;
	}
	return (out);
}