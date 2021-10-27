#ifndef _CMDS_H
#define _CMDS_H

# include "../variables.h"

void	*ft_calloc(int a, int b);
int		error(t_cmd *cmd);
void	free_double(char **double_ptr);
char	*fill_str(const char *str, char delim, int part);
char	**ft_split(const char *str, char delim);
int		ft_strcmp(const char *str1, const char *str2);
char	*ft_strdup(const char *str);
size_t	lenth(const char *s, const char *s0);
char	*ft_strjoin(const char *s, const char *s0);
char 	*ft_strjoin_w_quote(char *str);
int		ft_strlen(const char *str);
int		ft_strlen_double(const char **str);
char	*ft_strnstr(const char *str1, const char *str2, int n);

#endif