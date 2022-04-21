/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneyt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:03:13 by sneyt             #+#    #+#             */
/*   Updated: 2022/04/13 11:56:34 by sneyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_numlen(unsigned int a)
{
	int	count;

	count = 0;
	while (a > 0)
	{
		count++;
		a /= 10;
	}
	return (count);
}

char	*ft_unsitoa(unsigned int a)
{
	char	*ans;
	int		i;

	i = ft_numlen(a);
	ans = malloc(sizeof(char) * (i + 1));
	if (!ans)
		return (0);
	ans[i] = '\0';
	while (i > 0)
	{
		ans[i - 1] = (a % 10) + '0';
		a /= 10;
		i--;
	}
	return (ans);
}

int	ft_printunsnum(unsigned int a)
{
	int		print_len;
	char	*ans;

	print_len = 0;
	if (a == 0)
	{
		write(1, "0", 1);
		print_len += 1;
	}
	else
	{
		ans = ft_unsitoa(a);
		print_len = ft_printstr(ans);
		free(ans);
	}
	return (print_len);
}
