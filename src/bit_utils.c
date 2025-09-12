/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 18:13:09 by bmoreira          #+#    #+#             */
/*   Updated: 2025/09/11 22:12:22 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	bin = calloc(digits + 1, sizeof(char));
	while (--digits >= 0)
	{
		bin[digits] = set[n % base];
		n /= base;
	}
	return (bin);
}

int	powerof(int n, int power)
{
	int	res;

	res = n;
	if (power == 0)
		return (1);
	while (power-- > 1)
		res *= n;
	return (res);
}

int	btoi(char *b)
{
	int	num;
	int	pow;
	int	len;

	num = 0;
	pow = 0;
	len = strlen(b);
	while (len--)
		num += powerof(2, pow++) * (b[len] - 48);
	return (num);
}

int main(void)
{
	char *bs = itoba('Z', "01", 2);
	
	printf("ue %s\n", bs);
	printf("btoi %d", btoi(bs));
}