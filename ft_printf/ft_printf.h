/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segurbuz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 02:56:34 by segurbuz          #+#    #+#             */
/*   Updated: 2023/01/10 02:56:35 by segurbuz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	print_machine(char c);
int	printf_control(char c, va_list arg, char *hex);
int	print_array(const char *str);
int	print_pointer(unsigned long int pointer, char *hex);
int	putnbr(int n);
int	u_putnbr(unsigned int n);
int	hex_decimal(unsigned int n, char *hex, char c);

#endif
