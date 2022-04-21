/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneyt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:15:20 by sneyt             #+#    #+#             */
/*   Updated: 2022/04/20 11:34:27 by sneyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

int	ft_pointerlen(unsigned long nb)
{
	int	i;

	i = 0;
	while (nb != 0)
	{
		i++;
		nb /= 16;
	}
	return (i);
}

void	ft_putpointer(unsigned long nb)
{
	if (nb >= 16)
	{
		ft_putpointer(nb / 16);
		ft_putpointer(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + '0'), 1);
		else
			ft_putchar_fd((nb - 10 + 'a'), 1);
	}
}

int	ft_printpointer(unsigned long ptr)
{
	int	print_len;

	print_len = 0;
	print_len = write(1, "0x", 2);
	if (ptr == 0)
		print_len += write(1, "0", 1);
	else
	{
		ft_putpointer(ptr);
		print_len += ft_pointerlen(ptr);
	}
	return (print_len);
}
