/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 19:45:46 by bmoreira          #+#    #+#             */
/*   Updated: 2025/09/13 22:18:30 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	sig_ack(int sig)
{
	static int	count = 0;

	(void) sig;
	ft_printf("Received message %d!\n", count++);
}

void	send_bits(char *pid, unsigned char *bin)
{
	while (*bin)
	{
		if (*bin == '0')
			kill(ft_atoi(pid), SIGUSR1);
		if (*bin == '1')
			kill(ft_atoi(pid), SIGUSR2);
		pause();
		bin++;
	}
}

void	send_msg(char *pid, unsigned char *msg)
{	
	unsigned char	*bin;

	while (*msg)
	{
		bin = fill_bits(itoba(*msg++));
		send_bits(pid, bin);
	}
	if (!*msg)
		send_bits(pid, fill_bits(itoba('\n')));
	free(bin);
}

int	main(int argc, char *argv[])
{	
	if (argc != 3)
		_exit(0);
	signal(SIGUSR1, sig_ack);
	send_msg(argv[1], (unsigned char *) argv[2]);
	return (0);
}
