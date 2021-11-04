/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isghioua <isghioua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:50:27 by isghioua          #+#    #+#             */
/*   Updated: 2021/03/28 15:28:53 by isghioua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	words(char const *s, char c)
{
	int	i;
	int	nbr_of_words;

	i = 0;
	nbr_of_words = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			nbr_of_words++;
		}
	}
	return (nbr_of_words);
}

static int	fscape(char const *str, int i, char c)
{
	while (str[i] == c && str[i] != '\0')
		i++;
	return (i);
}

static int	size(char const *str, int i, char c)
{
	int	s;

	s = 0;
	while (str[i] != c && str[i] != '\0')
	{
		s++;
		i++;
	}
	return (s);
}

char	**ft_split(char const *str, char c)
{
	int		i;
	int		w;
	char	**ch;

	if (!str)
		return (0);
	ch = (char **)malloc((words(str, c) + 1) * sizeof(char *));
	if (!ch)
		return (0);
	w = words(str, c);
	i = 0;
	w = 0;
	while (w < words(str, c))
	{
		i = fscape(str, i, c);
		ch[w] = ft_substr(str, i, size(str, i, c));
		i += size(str, i, c);
		w++;
	}
	ch[w] = NULL;
	return (ch);
}
