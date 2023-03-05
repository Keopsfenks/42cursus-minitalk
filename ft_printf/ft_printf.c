/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:53:10 by segurbuz          #+#    #+#             */
/*   Updated: 2023/01/07 14:53:12 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_machine(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_pointer(unsigned long int pointer, char *hex)
{
	int	i;

	i = 0;
	if (pointer / 16 != 0)
		i += print_pointer(pointer / 16, hex);
	i += print_machine(hex[pointer % 16]);
	return (i);
}

int	printf_control(char c, va_list arg, char *hex)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += print_machine(va_arg(arg, int));
	else if (c == 's')
		len += print_array(va_arg(arg, char *));
	else if (c == 'p')
	{
		len += write(1, "0x", 2);
		len += print_pointer (va_arg(arg, unsigned long int), hex);
	}
	else if (c == 'd' || c == 'i')
		len += putnbr(va_arg(arg, int));
	else if (c == 'u')
		len += u_putnbr(va_arg(arg, int));
	else if (c == 'x' || c == 'X')
		len += hex_decimal(va_arg(arg, int), hex, c);
	else if (c == '%')
		len += print_machine('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		print_number;
	int		i;
	va_list	arg;

	i = 0;
	print_number = 0;
	va_start (arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			while (str[i] == ' ' || str[i] == '#' || str[i] == '+')
				i++;
			print_number += printf_control(str[i], arg, "0123456789abcdef");
			i++;
		}
		else
			print_number += print_machine(str[i++]);
	}
	return (print_number);
}
