/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 18:26:02 by segurbuz          #+#    #+#             */
/*   Updated: 2023/03/05 18:26:03 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include "./ft_printf/ft_printf.h"

int		ft_atoi(const char *str);
void	signal_recevier(int signal, siginfo_t *info, void *unused);
void	sending_success(int s_pid);
void	sending_string_plus(int s_pid, int c);
void	sending_message(int s_pid, unsigned char *msg);
#endif
