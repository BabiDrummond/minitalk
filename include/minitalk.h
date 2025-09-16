/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helios <helios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 19:42:02 by bmoreira          #+#    #+#             */
/*   Updated: 2025/09/16 00:28:40 by helios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/include/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

# define BASE 2
# define BITS 8
# define SET "01"

// CLIENT
void			sig_ack(int sig);
void			send_bits(int pid, unsigned char c);
void			send_msg(int pid, unsigned char *msg);

//SERVER
int				btoi(char *b);
void			sig_handler(int sig, siginfo_t *info, void *context);
void			init_sa(void);

#endif