/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:17:32 by bmoreira          #+#    #+#             */
/*   Updated: 2025/08/30 21:49:53 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	count_digits(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		negative;

	negative = 0;
	len = count_digits(n);
	str = ft_calloc(len + 1, sizeof(char));
	if (n == -2147483648)
		return ((char *) ft_memcpy(str, "-2147483648", len));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		str[negative] = '-';
		negative++;
	}
	while (--len >= negative)
	{
		str[len] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}
