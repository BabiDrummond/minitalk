/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 19:42:02 by bmoreira          #+#    #+#             */
/*   Updated: 2025/09/13 19:36:50 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/include/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

void			sig_handler(int sig, siginfo_t *info, void *context);
int				count_digits(int n, int base);
int				btoi(char *b);
unsigned char	*itoba(int n, char *set, int base);
unsigned char	*fill_bits(unsigned char *bin, int bits);

#endif