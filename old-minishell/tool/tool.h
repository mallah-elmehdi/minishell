
#ifndef TOOL_H
# define TOOL_H
// libft
char	*ft_calloc(int a, int b);
char	*ft_strdup(char *str);
int ft_strlen(char *s);
int	ft_strcmp(const char *str1, const char *str2);
int	ft_strcpy(char *dest, char *src);

// error
int error(void);

// other
int ft_strlen_v2(char **s);
int	ft_atoi(char *str);
char	**ft_env_list(char **env);
char	**ft_calloc_v2(int a, int b);
pid_t	start_process(void);
#endif
