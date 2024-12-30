/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iumorave <iumorave@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:07:26 by iumorave          #+#    #+#             */
/*   Updated: 2024/12/30 19:04:34 by iumorave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_word(char const *s, char c)
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
	int		i;
	int		len;
	char	*next_word;
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
char **split(char *s, char c)
{
	int		str_count;
	int		i;
	char	**res_array;


	i = 0;
	str_count = count_word(s, c);
	if (!str_count)
		return (NULL);
	res_array = malloc(sizeof(char *) * (size_t)(str_count + 1));
	if (!res_array)
		return NULL;
	if (s[0] == c)
	{
		res_array[i] = malloc(sizeof(char));
		if (!res_array)
		{
			free(res_array);
			return NULL;
		}
		res_array[i++][0] = '\0';
	}
	while (i < str_count)
	{
		res_array[i] = get_next_word(s, c);
		if (!res_array[i])
		{
			while (i-- >= 0)
				free(res_array[i]);
			free(res_array);
			return NULL;
		}
		i++;
	}
	res_array[i] = NULL;
	return (res_array);
}
