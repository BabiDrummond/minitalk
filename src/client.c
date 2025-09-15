/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 19:45:46 by bmoreira          #+#    #+#             */
/*   Updated: 2025/09/14 21:01:35 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	sig_ack(int sig)
{
	static int	count = 0;
	static int	chars = -1;
	
	usleep(250);
	if (!(count % BITS))
		chars++;
	ft_printf("Received message: %d! Printed chars: %d.\n", count++, chars);
	(void) sig;
}

void	send_bits(char *pid, unsigned char *bin)
{
	while (*bin)
	{
		if (*bin == '0')
			kill(ft_atoi(pid), SIGUSR1);
		if (*bin == '1')
			kill(ft_atoi(pid), SIGUSR2);
		bin++;
		pause();
	}
}

void	send_msg(char *pid, unsigned char *msg)
{	
	unsigned char	*bin;

	while (*msg)
	{
		bin = fill_bits(itoba(*msg++));
		send_bits(pid, bin);
		free(bin);
	}
	send_bits(pid, (unsigned char *)"00001010");
}

int	main(int argc, char *argv[])
{	
	if (argc != 3 && ft_printf("Command: ./client PID MESSAGE\n"))
		return (1);
	signal(SIGUSR1, sig_ack);
	send_msg(argv[1], (unsigned char *) argv[2]);
	return (0);
}
