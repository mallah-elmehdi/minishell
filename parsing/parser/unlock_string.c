#include "../../minishell.h"

void	unlock_string(char *content, t_ast *s_cmd, char **table_of_env_var)
{
	char	*str;
	char	*new_str;
	char	*cap_content;
	int		i;

	i = 0;
	cap_content = ft_strdup("");
	while (content[i] != '\0')
	{
		if (content[i] == '\'')
			new_str = extract_string_within_quotes(content, &i, '\'');
		else if (content[i] == '"')
			new_str = expand_string_within_double_quotes(table_of_env_var,
				extract_string_within_quotes(content, &i, '"'));
		else if (content[i] == '$')
		{
			new_str = extract_string_within_dollar_sign(s_cmd, &cap_content,
				expand_dollar_sign(content, &i,table_of_env_var));
			// printf("|%s|\n", cap_content);
			// printf("|%s|\n", new_str);
			// exit (1);
		}
		else
			new_str = ft_substr(content, i, 1);
		i++;
		str = ft_strjoin(cap_content, new_str);
		free(cap_content);
		cap_content = NULL;
		free(new_str);
		new_str = NULL;
		cap_content = ft_strdup(str);
		free(str);
		str = NULL;
	}
	add_string_to_table_of_args(&cap_content, s_cmd);
}
