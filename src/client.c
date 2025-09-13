/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 19:45:46 by bmoreira          #+#    #+#             */
/*   Updated: 2025/09/12 18:41:43 by bmoreira         ###   ########.fr       */
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
	}
}

void	translate_msg(char *pid, char *msg)
{
	char *bin_ascii;
	
	while (*msg)
	{
		bin_ascii = itoba(*msg++, "01", 2);
		send_msg(pid, bin_ascii);
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 3)
		send_msg(argv[1], argv[2]);
	return (0);
}