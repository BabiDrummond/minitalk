/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: helios <helios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 19:45:41 by bmoreira          #+#    #+#             */
/*   Updated: 2025/09/16 12:06:14 by helios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	btoi(char *b)
{
	int		num;
	size_t	i;

	num = 0;
	i = 0;
	while (i < ft_strlen((char *) b))
		num = num * BASE + (b[i++] - 48);
	return (num);
}

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static char	*bin = NULL;
	static int	i = 0;

	if (bin == NULL)
		bin = ft_calloc(BITS + 1, sizeof(char));
	if (sig == SIGUSR1)
		bin[i++] = '0';
	if (sig == SIGUSR2)
		bin[i++] = '1';
	if (i == BITS && ft_printf("%c", btoi(bin)))
	{
		i = 0;
		free(bin);
		bin = NULL;
	}
	kill(info->si_pid, SIGUSR1);
	(void) context;
}

void	init_sa(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) && ft_printf("Error in SIGUSR1"))
		exit(1);
	if (sigaction(SIGUSR2, &sa, NULL) && ft_printf("Error in SIGUSR2"))
		exit(2);
}

int	main(void)
{
	init_sa();
	ft_printf("SERVER PID: %d\n", getpid());
	while (1)
		pause();
}
