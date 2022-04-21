/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneyt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:00:12 by sneyt             #+#    #+#             */
/*   Updated: 2022/04/20 11:37:06 by sneyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_getformat(va_list ap, const char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len += ft_putchar(va_arg(ap, int));
	else if (format == 's')
		print_len += ft_printstr(va_arg(ap, char *));
	else if (format == 'd' || format == 'i')
		print_len += ft_printnum(va_arg(ap, int));
	else if (format == 'u')
		print_len += ft_printunsnum(va_arg(ap, unsigned int));
	else if (format == 'x' || format == 'X')
		print_len += ft_printhex(va_arg(ap, unsigned int), format);
	else if (format == '%')
		print_len += ft_printpercent();
	else if (format == 'p')
		print_len += ft_printpointer(va_arg(ap, unsigned long));
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		print_len;

	i = 0;
	print_len = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_len += ft_getformat(ap, str[i + 1]);
			i++;
		}
		else
		{
			print_len += ft_putchar(str[i]);
		}
		i++;
	}	
	va_end(ap);
	return (print_len);
}
