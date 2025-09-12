/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 19:45:41 by bmoreira          #+#    #+#             */
/*   Updated: 2025/09/11 17:58:24 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void sig_handler(int sig, siginfo_t *info, void *context)
{
	ft_printf("Receiving signal %d from PID: %d", sig, info->si_pid);
	(void) context;
	_exit(0);
}

int	main(void)
{
	struct sigaction sa;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	sigemptyset(&sa.sa_mask);

	sigaction(SIGUSR1, &sa, NULL);
	ft_printf("%d\n", getpid());
	while (1)
	{
		ft_printf("Aguardando...\n");
		sleep(1);
	}
}