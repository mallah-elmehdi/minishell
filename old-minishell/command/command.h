#ifndef COMMAND_H
# define COMMAND_H
int	ft_cd(const char *path);
int	ft_echo(t_command *command, char **env);
int	ft_env(t_command *command, char **env);
int	ft_exit(t_command *command);
int	ft_pwd(t_command *command);
int	ft_export(t_command *command, char **env);

int contains(char *str);
char	*ft_update_arg(char *str, char **env);
char	*ft_update(char *str, char **env);
char 	*ft_qote_out(char *str, char c);
int	ft_stop(char *str, char c);


int	is_num(char c);
int	is_alpha(char c);
char	*ft_strdollar(char *str);
char	*ft_strenv(char *str, char **env);
char	*ft_dollar(char *str, char **env);
char	**ft_split(char *str, char c);
char	*ft_slash(char *str);
char	*ft_strfcpy(char *str, char c);
char	*ft_strbcpy(char *str, char c);
int	ft_start(char *str, char c);
void	free_v2(char **str);
char	*ft_strmcpy(char *str, char c);
char	*ft_strlcpy(char *str, char c);
char	**ft_split_quote_out(char *str, char c);
char	*ft_join_quote_out(char *str, char c);
void	ft_dollar_help(char *str, char *temp, char *strenv);


t_command	*ft_get_the_struct(char *command);
#endif