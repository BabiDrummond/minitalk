/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 20:57:59 by bmoreira          #+#    #+#             */
/*   Updated: 2025/08/30 21:49:16 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putchr(int c)
{
	return (write(1, &c, 1));
}

int	ft_put_s(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_put_s("(null)"));
	while (s[i])
		ft_putchr(s[i++]);
	return (i);
}

int	ft_put_n(int n, char *set, int base)
{
	int	digits;

	if (n == -2147483648)
		return (ft_put_s("-2147483648"));
	digits = count_n(n, base);
	if (n < 0 && ft_putchr('-'))
		n *= -1;
	if (n / base)
		ft_put_n(n / base, set, base);
	ft_putchr(set[n % base]);
	return (digits);
}

int	ft_putul(unsigned long n, char *set, int base)
{
	if (n / base)
		ft_putul(n / base, set, base);
	ft_putchr(set[n % base]);
	return (count_ul(n, base));
}

int	ft_putptr(unsigned long p)
{
	if (!p)
		return (ft_put_s("(nil)"));
	return (ft_put_s("0x") + ft_putul(p, "0123456789abcdef", 16));
}
