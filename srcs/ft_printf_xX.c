/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneyt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:39:23 by sneyt             #+#    #+#             */
/*   Updated: 2022/04/20 10:01:26 by sneyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_hexlen(unsigned int a)
{
	int	count;

	count = 0;
	while (a > 0)
	{
		count++;
		a /= 16;
	}
	return (count);
}

void	ft_put_hex(unsigned int a, const char format)
{
	if (a >= 16)
	{
		ft_put_hex(a / 16, format);
		ft_put_hex(a % 16, format);
	}
	else
	{
		if (a <= 9)
			ft_putchar_fd(a + '0', 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd(a - 10 + 'a', 1);
			else if (format == 'X')
				ft_putchar_fd(a - 10 + 'A', 1);
		}
	}
}

int	ft_printhex(unsigned int a, const char format)
{
	int	print_len;

	if (a == 0)
	{
		write(1, "0", 1);
		print_len = 1;
	}
	else
	{
		print_len = ft_hexlen(a);
		ft_put_hex(a, format);
	}
	return (print_len);
}

int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}
