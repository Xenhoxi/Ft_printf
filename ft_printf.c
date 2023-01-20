/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerinec <ljerinec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:59:59 by ljerinec          #+#    #+#             */
/*   Updated: 2022/12/13 16:24:46 by ljerinec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	check_arg(va_list param, const char *format, int *size)
{
	if (*format == 's')
		ft_putstr(va_arg(param, char *), size);
	else if (*format == '%')
		ft_putchar('%', size);
	else if (*format == 'c')
		ft_putchar(va_arg(param, int), size);
	else if (*format == 'd' || *format == 'i')
		ft_putnbr(va_arg(param, int), size);
	else if (*format == 'u')
		ft_putunbr(va_arg(param, unsigned int), size);
	else if (*format == 'p')
	{
		ft_putstr("0x", size);
		if (*size == -1)
			return ;
		ft_putnbr_hexa(va_arg(param, unsigned long), *format, size);
	}
	else if (*format == 'x' || *format == 'X')
		ft_putnbr_hexa(va_arg(param, unsigned int), *format, size);
	else
		ft_putchar(*format, size);
}

int	ft_printf(const char *format, ...)
{
	int		size;
	int		i;
	va_list	param;

	va_start(param, format);
	size = 0;
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
			check_arg(param, &format[++i], &size);
		else if (format[i] != '%')
			ft_putchar(format[i], &size);
		if (size == -1)
			return (size);
	}
	va_end(param);
	return (size);
}
