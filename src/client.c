/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 19:45:46 by bmoreira          #+#    #+#             */
/*   Updated: 2025/09/13 17:52:30 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	send_msg(char *pid, char *bin)
{
	while (*bin)
	{
		if (*bin == '0')
			kill(ft_atoi(pid), SIGUSR1);
		else if (*bin == '1')
			kill(ft_atoi(pid), SIGUSR2);
		bin++;
		usleep(200);
	}
}

void	translate_msg(char *pid, char *msg)
{
	char *bin_ascii;
	
	while (*msg)
	{
		bin_ascii = fill_bits(itoba(*msg++, "01", 2), 8);
		send_msg(pid, bin_ascii);
	}
	if (!*msg)
	{
		bin_ascii = fill_bits(itoba('\n', "01", 2), 8);
		send_msg(pid, bin_ascii);
	}
}

int	main(int argc, char *argv[])
{
	if (argc > 1 && ft_printf("%s\n", argv[2]))
		translate_msg(argv[1], argv[2]);
	//kill(ft_atoi(argv[1]), SIGUSR1);
	return (0);
}