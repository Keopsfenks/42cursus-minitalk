/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 23:48:18 by segurbuz          #+#    #+#             */
/*   Updated: 2023/02/26 23:48:19 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		result = (str[i] - '0') + (result * 10);
		i++;
	}
	return (result);
}
