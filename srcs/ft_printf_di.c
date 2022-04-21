/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneyt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:00:26 by sneyt             #+#    #+#             */
/*   Updated: 2022/04/13 11:56:55 by sneyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printnum(int num)
{
	int		len;
	char	*number;

	number = ft_itoa(num);
	len = ft_printstr(number);
	free(number);
	return (len);
}
