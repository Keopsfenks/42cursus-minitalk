/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:57:21 by segurbuz          #+#    #+#             */
/*   Updated: 2023/02/25 23:57:24 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_recevier(int signal, siginfo_t *info, void *unused)
{
	int			sig;
	static int	set = 0;
	static int	byte = 7;

	(void)unused;
	if (signal == SIGUSR1)
		sig = 0;
	if (signal == SIGUSR2)
		sig = 1;
	set += sig << byte;
	if (byte == 0)
	{
		if (set == '\0')
			kill(info->si_pid, SIGUSR1);
		ft_printf("%c", set);
		set = 0;
		byte = 7;
	}
	else
		byte--;
}

int	main(void)
{
	struct sigaction	client;

	client.sa_flags = SA_SIGINFO;
	client.sa_sigaction = signal_recevier;
	ft_printf("Get Pid: %d\n", getpid());
	if (sigaction(SIGUSR1, &client, 0) == -1)
		ft_printf("signal not received!");
	if (sigaction(SIGUSR2, &client, 0) == -1)
		ft_printf("signal not received!");
	while (1)
		pause();
	return (0);
}
