#ifndef MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>

typedef struct s_cmd 
{
	char	*cmd;
	char	*arg;
	char	**opt;
	char	**env;
}	t_cmd;

// ----- util
char	*ft_strnstr(const char *str1, const char *str2, int n);
char	*ft_strdup(const char *str);
void	*ft_calloc(int a, int b);
int		ft_strlen(const char *str);
char	**ft_split(const char *str, char delim);
void	free_double(char **double_ptr);
char	*ft_strjoin(const char *s, const char *s0);
int		error(t_cmd *cmd);
// ----- cmds
int		init_cmds(t_cmd *cmds, char **env);
int		ft_cmds(t_cmd *cmds);
// ----- cd
int		cd(t_cmd *cmd);
char	*cd_path(const char *path, char **env);
char	*abs_path(const char *path, char **env);
// ----- pwd
int		pwd(t_cmd *cmd);
int		pwd_path_length(char **env);

#define MINISHELL_H
#endif