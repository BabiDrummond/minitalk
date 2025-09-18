/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 19:45:46 by bmoreira          #+#    #+#             */
/*   Updated: 2025/09/18 19:22:44 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

t_ack	g_ack = {0, 0};

void	sig_ack(int sig)
{
	if (sig == SIGUSR1)
		g_ack.confirm = 1;
}

void	send_bits(int pid, unsigned char c)
{
	unsigned char	*bin;
	int				i;

	i = 0;
	bin = fill_bits(itoba(c));
	while (bin[i])
	{
		g_ack.confirm = 0;
		if (bin[i] == '0')
			kill(pid, SIGUSR1);
		if (bin[i] == '1')
			kill(pid, SIGUSR2);
		while (!g_ack.confirm)
			;
		i++;
		g_ack.count++;
	}
	free(bin);
	bin = NULL;
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
	ft_printf("Acknowledge %d messages! Printed %d chars.\n",
		g_ack.count, g_ack.count / BITS);
	return (0);
}
