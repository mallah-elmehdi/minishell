/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:32:37 by isghioua          #+#    #+#             */
/*   Updated: 2021/11/05 21:42:02 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**ft_realloc_table(char **args, int i)
{
	char	**new_args;
	int		size;
	int		j;

	j = 0;
	size = get_size_of_table(args);
	new_args = malloc(sizeof(char *) * (size + i + 1));
	while (j < size)
	{
		new_args[j] = args[j];
		j++;
	}
	free(args);
	args = NULL;
	return (new_args);
}
