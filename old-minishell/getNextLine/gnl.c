#include "../minishell.h"

int		get_next_line(int fd, char **line)
{
	int i;	
	char temp[1001];
	
	i = 0;
	if (!line)
		return (SUCCESS);
	*line = (char*)ft_calloc(sizeof(char), 1001);
	if (!(line))
		return (ERROR);
	while (1)
	{
		if (read(fd, temp, 1000) == ERROR)
			return (error());
		if (!check_line(temp, *line))
			return (SUCCESS);
		ft_realloc(*line);
	}
	return (SUCCESS);
}