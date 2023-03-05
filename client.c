/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 05:45:50 by segurbuz          #+#    #+#             */
/*   Updated: 2023/02/26 05:45:51 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	success_message(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("Message sent successfully!");
}

void	sending_message(int s_pid, unsigned char *msg)
{
	int	i;
	int	c;

	c = 0;
	i = 128;
	while (msg[c] != '\0')
	{
		while (i >= 1)
		{
			if (msg[c] / i)
			{
				kill(s_pid, SIGUSR2);
				msg[c] = msg[c] - i;
			}
			else
				kill(s_pid, SIGUSR1);
			usleep(100);
			i /= 2;
		}
		i = 128;
		c++;
	}
}

void	sending_string_plus(int s_pid, int c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
			kill(s_pid, SIGUSR2);
		else
			kill(s_pid, SIGUSR1);
		usleep(100);
		i--;
	}
}

int	main(int ac, char **av)
{
	int				s_pid;
	unsigned char	*msg;

	if (ac != 3)
	{
		ft_printf("Wrong Usage!");
		return (0);
	}
	s_pid = ft_atoi(av[1]);
	signal(SIGUSR1, success_message);
	msg = (unsigned char *)av[2];
	sending_message(s_pid, msg);
	sending_string_plus(s_pid, '\n');
	sending_string_plus(s_pid, '\0');
	return (0);
}
