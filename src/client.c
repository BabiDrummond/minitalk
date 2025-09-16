/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helios <helios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 19:45:46 by bmoreira          #+#    #+#             */
/*   Updated: 2025/09/16 12:05:38 by helios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

t_ack	g_ack = {0, 0};

void	sig_ack(int sig)
{
	if (sig == SIGUSR1)
		g_ack.confirm = 1;
	(void) sig;
}

void	send_bits(int pid, unsigned char c)
{
	unsigned char	bin;

	bin = 1 << 7;
	while (bin > 0)
	{
		g_ack.confirm = 0;
		if (bin & c)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!g_ack.confirm)
			;
		bin = bin >> 1;
		g_ack.count++;
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
	ft_printf("Acknowledge %d messages! Printed %d chars.\n", g_ack.count, g_ack.count / BITS);
	return (0);
}
