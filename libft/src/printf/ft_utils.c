/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 07:48:11 by bmoreira          #+#    #+#             */
/*   Updated: 2025/08/30 21:49:21 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	count_n(int n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0 && ++len)
		n *= -1;
	while (n && ++len)
		n = n / base;
	return (len);
}

int	count_ul(unsigned long n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n && ++len)
		n = n / base;
	return (len);
}

int	check_case(char *set, char c)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

int	put_case(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchr(va_arg(args, int)));
	if (c == 's')
		return (ft_put_s(va_arg(args, char *)));
	if (c == 'd' || c == 'i')
		return (ft_put_n(va_arg(args, int), "0123456789", 10));
	if (c == 'u')
		return (ft_putul(va_arg(args, unsigned int), "0123456789", 10));
	if (c == 'p')
		return (ft_putptr(va_arg(args, unsigned long)));
	if (c == 'x')
		return (ft_putul(va_arg(args, unsigned int), "0123456789abcdef", 16));
	if (c == 'X')
		return (ft_putul(va_arg(args, unsigned int), "0123456789ABCDEF", 16));
	return (0);
}
