/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 19:45:46 by bmoreira          #+#    #+#             */
/*   Updated: 2025/09/13 19:45:25 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	sig_ack(int sig)
{
	static int	count = 0;

	(void) sig;
	ft_printf("Received message %d!\n", count++);
}

void	send_msg(char *pid, unsigned char *bin)
{
	while (*bin)
	{
		if (*bin == '0')
			kill(ft_atoi(pid), SIGUSR1);
		if (*bin == '1')
			kill(ft_atoi(pid), SIGUSR2);
		bin++;
		usleep(200);
	}
}

void	translate_msg(char *pid, unsigned char *msg)
{	
	while (*msg)
		send_msg(pid, fill_bits(itoba(*msg++, "01", 2), 8));
	if (!*msg)
		send_msg(pid, fill_bits(itoba('\n', "01", 2), 8));
}

int	main(int argc, char *argv[])
{	
	if (argc != 3)
		_exit(0);
	signal(SIGUSR1, sig_ack);
	translate_msg(argv[1], (unsigned char *) argv[2]);
	return (0);
}
