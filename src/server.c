/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoreira <bmoreira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 19:45:41 by bmoreira          #+#    #+#             */
/*   Updated: 2025/09/13 19:45:51 by bmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	g_pid = 0;

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static char	*bin = NULL;
	static int	i = 0;

	(void) context;
	g_pid = info->si_pid;
	if (bin == NULL)
		bin = ft_calloc(9, sizeof(char));
	if (sig == SIGUSR1)
		bin[i++] = '0';
	if (sig == SIGUSR2)
		bin[i++] = '1';
	if (i == 8 && ft_printf("%c", btoi(bin)))
		i = 0;
	kill(g_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("SERVER PID: %d\n", getpid());
	while (1)
		pause();
}
