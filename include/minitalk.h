/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 19:42:02 by bmoreira          #+#    #+#             */
/*   Updated: 2025/09/27 22:30:12 by bmoreira         ###   ########.fr       */
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

typedef struct s_ack
{
	int		confirm;
	int		count;
}	t_ack;

extern t_ack	g_ack;

// CLIENT
unsigned char	*fill_bits(unsigned char *binary);
void			sig_ack(int sig);
void			send_bits(int pid, unsigned char c);
void			send_msg(int pid, unsigned char *msg);

//SERVER
int				btoi(char *b);
void			sig_handler(int sig, siginfo_t *info, void *context);
void			init_sa(void);

#endif