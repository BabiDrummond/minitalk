/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 18:13:09 by bmoreira          #+#    #+#             */
/*   Updated: 2025/09/13 17:40:46 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	count_digits(int n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n && ++len)
		n = n / base;
	return (len);
}

char	*itoba(int n, char *set, int base)
{
	char	*bin;
	int		digits;
	
	digits = count_digits(n, base);
	bin = ft_calloc(digits + 1, sizeof(char));
	while (--digits >= 0)
	{
		bin[digits] = set[n % base];
		n /= base;
	}
	return (bin);
}

int	btoi(char *b)
{
	int	num;
	int i;

	num = 0;
	i = 0;
	while (i < (int) ft_strlen(b))
		num = num * 2 + (b[i++] - 48);
	return (num);
}

char	*fill_bits(char *bin, int bits)
{
	char	*filled;
	int		rest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	rest = bits - ft_strlen(bin);
	if (rest)
	{
		filled = ft_calloc(bits + 1, sizeof(char));
		while (i < rest)
			filled[i++] = '0';
		while (i < bits)
			filled[i++] = bin[j++];
		free(bin);
	}
	else
		filled = bin;
	return (filled);
}
