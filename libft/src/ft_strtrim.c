/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:54:01 by bmoreira          #+#    #+#             */
/*   Updated: 2025/08/30 21:53:42 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	countchr(char *str, char *set, int pos, int inc)
{
	char	*temp_set;
	int		count;

	temp_set = (char *) set;
	count = 0;
	while (*set)
	{
		if (str[pos] == *set++)
		{
			pos += inc;
			count++;
			set = temp_set;
		}
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		len;
	int		start;
	int		end;

	len = ft_strlen(s1);
	if (!s1 || (!s1 && !set))
		return (ft_strdup(""));
	start = countchr((char *) s1, (char *)set, 0, 1);
	end = countchr((char *)s1, (char *)set, len - 1, -1);
	if (start == len && end == len)
		return (ft_strdup(""));
	new = ft_calloc(len - start - end + 1, sizeof(char));
	if (!new)
		return (NULL);
	ft_memcpy(new, (s1 + start), len - start - end);
	return (new);
}
