/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 18:13:09 by bmoreira          #+#    #+#             */
/*   Updated: 2025/09/11 22:14:52 by bmoreira         ###   ########.fr       */
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

int	btoi(char *b)
{
	int	num;
	int i;

	num = 0;
	i = 0;
	while (i < (int) strlen(b))
		num = num * 2 + (b[i++] - 48);
	return (num);
}

int main(void)
{
	char *bs = itoba('Z', "01", 2);
	
	printf("ue %s\n", bs);
	printf("btoi %d", btoi(bs));
}