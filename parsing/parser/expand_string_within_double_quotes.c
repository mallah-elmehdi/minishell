#include "../../minishell.h"

char    *expand_string_within_double_quotes(char **table_of_env_var, char *content)
{
    int     i;
    int     j;
    char    *str;
    char    *cap_content;
    char    *new_str;

    if (ft_strchr(content, '$') == NULL)
        return (content);
    i = 0;
    cap_content = ft_strdup("");
    while (content[i])
    {
        j = 0;
        while (content[i] && content[i] != '$')
        {
            i++;
            j++;
        }
        str = ft_substr(content, (i -j), j);
        new_str = ft_strjoin(cap_content, str);
        free(cap_content);
        cap_content = NULL;
        free(str);
        str = NULL;
        cap_content = ft_strdup(new_str);
        free(new_str);
        new_str = NULL;
        if (content[i] == '$')
        {
            str = expand_dollar_sign(content, &i, table_of_env_var);
            new_str = ft_strjoin(cap_content, str);
            free(cap_content);
            cap_content = NULL;
            free(str);
            str = NULL;
            cap_content = ft_strdup(new_str);
            free(new_str);
            new_str = NULL;
            i++;
        }
    }
    return (cap_content);
}
