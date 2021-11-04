#include "../../minishell.h"

char	*extract_string_within_quotes(char *content, int *index, char char_quote)
{
	char	*new_content;
	int		length;

	length = find_closing_quote(content, *index, char_quote);
	if (length == 0)
	{
		new_content = ft_substr(content, *index, 1);
		(*index)++;
	}
	else
	{
		*index += 1;
		new_content = ft_substr(content, *index, length);
		*index += length;
	}
	return (new_content);
}
