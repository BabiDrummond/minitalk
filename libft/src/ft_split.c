/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 18:21:44 by bmoreira          #+#    #+#             */
/*   Updated: 2025/08/30 21:52:23 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	count_words(char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (!s || !*s)
		return (count);
	if (s[i++] != c)
		count++;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

static char	**free_all(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		word;
	int		letter;

	word = 0;
	arr = ft_calloc((count_words((char *) s, c) + 1), sizeof(char *));
	if (!arr)
		return (NULL);
	while (*s && *s == c)
		s++;
	while (*s)
	{
		letter = 0;
		arr[word] = ft_calloc(word_len((char *)s, c) + 1, sizeof(char));
		if (!arr[word])
			return (free_all(arr));
		while (*s && *s != c)
			arr[word][letter++] = *s++;
		while (*s && *s == c)
			s++;
		word++;
	}
	return (arr);
}
