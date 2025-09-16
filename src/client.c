/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helios <helios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 19:45:46 by bmoreira          #+#    #+#             */
/*   Updated: 2025/09/16 00:16:13 by helios           ###   ########.fr       */
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

void	send_bits(int pid, unsigned char c)
{
	unsigned	bin;

	bin = 1 << 7;
	while (bin > 0)
	{
		if (bin & c)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bin = bin >> 1;
		pause();
	}
}

void	send_msg(int pid, unsigned char *msg)
{
	while (*msg)
		send_bits(pid, *msg++);
	send_bits(pid, (unsigned char) '\n');
}

int	main(int argc, char *argv[])
{
	int	pid;

	pid = ft_atoi(argv[1]);
	if (argc != 3 && ft_printf("Command: ./client PID MESSAGE\n"))
		return (1);
	if (pid < 1 && ft_printf("Invalid pid.\n"))
		return (1);
	signal(SIGUSR1, sig_ack);
	send_msg(pid, (unsigned char *) argv[2]);
	return (0);
}
