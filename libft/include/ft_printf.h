/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:29:46 by bmoreira          #+#    #+#             */
/*   Updated: 2025/08/27 19:19:06 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	count_n(int n, int base);
int	count_ul(unsigned long n, int base);
int	check_case(char *set, char c);
int	put_case(char c, va_list args);
int	ft_putchr(int c);
int	ft_put_s(char *s);
int	ft_put_n(int n, char *set, int base);
int	ft_putul(unsigned long n, char *set, int base);
int	ft_putptr(unsigned long p);

#endif