/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 03:01:46 by segurbuz          #+#    #+#             */
/*   Updated: 2023/01/10 03:01:47 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_array(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (write (1, "(null)", 6));
	while (str[i])
		write (1, &str[i++], 1);
	return (i);
}

int	putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i += print_machine('-');
		i += putnbr(214748364);
		i += print_machine('8');
	}
	else if (n >= 0 && n < 10)
	{
		i += print_machine((n + '0'));
	}
	else if (n >= 10)
	{
		i += putnbr((n / 10));
		i += print_machine((n % 10 + '0'));
	}
	else
	{
		i += print_machine('-');
		i += putnbr((n * -1));
	}
	return (i);
}

int	u_putnbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 0 && n < 10)
	{
		i += print_machine((n + '0'));
	}
	else if (n >= 10)
	{
		i += putnbr((n / 10));
		i += print_machine((n % 10 + '0'));
	}
	else
	{
		i += putnbr((n * -1));
	}
	return (i);
}

static int	toupper(int str)
{
	while (str >= 'a' && str <= 'z')
	{
		str -= 32;
	}
	return (str);
}

int	hex_decimal(unsigned int n, char *hex, char c)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		i += print_machine('0');
		return (i);
	}
	if (n / 16 != 0)
		i += hex_decimal(n / 16, hex, c);
	if (c == 'x')
		i += print_machine(hex[n % 16]);
	else if (c == 'X')
		i += print_machine(toupper(hex[n % 16]));
	return (i);
}
