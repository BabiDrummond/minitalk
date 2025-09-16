/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helios <helios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 18:13:09 by bmoreira          #+#    #+#             */
/*   Updated: 2025/09/15 23:24:17 by helios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	count_digits(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n && ++len)
		n = n / BASE;
	return (len);
}

int	btoi(char *b)
{
	int		num;
	size_t	i;

	num = 0;
	i = 0;
	while (i < ft_strlen((char *) b))
		num = num * BASE + (b[i++] - 48);
	return (num);
}

unsigned char	*itoba(int n)
{
	unsigned char	*bin;
	int				digits;

	digits = count_digits(n);
	bin = ft_calloc(digits + 1, sizeof(char));
	if (!bin)
		return (NULL);
	while (--digits >= 0)
	{
		bin[digits] = SET[n % BASE];
		n /= BASE;
	}
	return (bin);
}

unsigned char	*fill_bits(unsigned char *bin)
{
	unsigned char	*filled;
	int				rest;
	int				i;
	int				j;

	i = 0;
	j = 0;
	rest = BITS - ft_strlen((char *)bin);
	if (rest == BITS)
		return (bin);
	filled = ft_calloc(BITS + 1, sizeof(char));
	if (!filled)
		return (free(bin), NULL);
	while (i < rest)
		filled[i++] = '0';
	while (i < BITS)
		filled[i++] = bin[j++];
	free(bin);
	return (filled);
}
