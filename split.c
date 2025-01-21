/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iumorave <iumorave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:07:26 by iumorave          #+#    #+#             */
/*   Updated: 2025/01/18 21:09:21 by iumorave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	w_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != c)
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char	*get_next_word(char *s, char c)
{
	int			i;
	int			len;
	char		*next_word;
	static int	cursor = 0;

	i = 0;
	len = 0;
	while (s[cursor] == c)
		cursor++;
	while (s[cursor + len] && (s[cursor + len] != c))
		len++;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while (s[cursor] && s[cursor] != c)
	{
		next_word[i] = s[cursor];
		i++;
		cursor++;
	}
	next_word[i] = '\0';
	return (next_word);
}

char	**split(char *s, char c)
{
	size_t		len;
	int			i;
	char		**res;

	i = 0;
	len = w_count(s, c);
	res = malloc(sizeof(char *) * (len + 1));
	if (!res)
		return (NULL);
	while (len-- >= 0)
	{
		if (i == 0)
		{
			res[i] = malloc(sizeof(char));
			if (!res[i])
				return (NULL);
			res[i++][0] = '\0';
			continue ;
		}
		res[i++] = get_next_word(s, c);
	}
	res[i] = NULL;
	return (res);
}
