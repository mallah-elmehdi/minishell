#ifndef MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>

typedef struct s_env_export 
{
	char	**export;
	char	**env;
}	t_env_export;

typedef struct s_cmd 
{
	char			*cmd;
	char			*arg;
	char			**opt;
	t_env_export	*env_export;
}	t_cmd;

// ----- util
char	*ft_strnstr(const char *str1, const char *str2, int n);
char	*ft_strdup(const char *str);
void	*ft_calloc(int a, int b);
int		ft_strlen(const char *str);
int		ft_strlen_double(const char **str);
char	**ft_split(const char *str, char delim);
void	free_double(char **double_ptr);
char	*ft_strjoin(const char *s, const char *s0);
int		ft_strcmp(const char *str1, const char *str2);
int		error(t_cmd *cmd);
// ----- cmds/cmds
int		ft_cmds(t_cmd *cmds);
// ----- cmds/init
t_cmd			*init_cmds(t_env_export *env_export);
t_env_export	*init_env_export(const char **menv);
// ----- cd
int		cd(t_cmd *cmd);
char	*cd_path(const char *path, char **env);
char	*abs_path(const char *path, char **env);
int		update_env_export(char *path, t_env_export *env_export);
// ----- pwd
int		pwd(t_cmd *cmd);
int		pwd_path_length(char **env);
char	*get_old_pwd(char **env);
// ----- env
char	**init_env(const char **menv);
int		update_env(char *new_pwd, char **env);
// ----- export
int		*init_sort_table(const char **menv);
int		*sort_table(const char **menv);
char	**init_export(const char **menv);
int		update_export(char *path, char **export);

#define MINISHELL_H
#endif