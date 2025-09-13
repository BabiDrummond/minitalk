/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 19:42:02 by bmoreira          #+#    #+#             */
/*   Updated: 2025/09/13 15:47:57 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/include/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

void	sig_handler(int sig, siginfo_t *info, void *context);
int		count_digits(int n, int base);
int		btoi(char *b);
char	*itoba(int n, char *set, int base);
char	*fill_bits(char *bin, int bits);

#endif