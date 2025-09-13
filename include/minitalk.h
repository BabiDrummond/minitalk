/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 19:42:02 by bmoreira          #+#    #+#             */
/*   Updated: 2025/09/12 18:31:08 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/include/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

void	sig_handler(int sig, siginfo_t *info, void *context);
char	*itoba(int n, char *set, int base);
int		btoi(char *b);
int		count_digits(int n, int base);

#endif