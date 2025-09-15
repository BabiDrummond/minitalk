/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 19:42:02 by bmoreira          #+#    #+#             */
/*   Updated: 2025/09/14 21:07:12 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/include/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

#  define BASE 2
#  define BITS 8
#  define SET "01"

// BIT_UTILS
int				count_digits(int n);
int				btoi(char *b);
unsigned char	*itoba(int n);
unsigned char	*fill_bits(unsigned char *binary);

// CLIENT
void        	sig_ack(int sig);
void        	send_bits(char *pid, unsigned char *bin);
void            send_msg(char *pid, unsigned char *msg);

//SERVER
void			sig_handler(int sig, siginfo_t *info, void *context);
void            init_sa(void);

#endif