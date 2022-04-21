/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneyt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:57:27 by sneyt             #+#    #+#             */
/*   Updated: 2022/04/13 12:02:39 by sneyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	size_t	len;
	char	*dupe;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	dupe = (char *)malloc((len + 1) * sizeof(char));
	if (!dupe)
		return (0);
	while (i < len)
	{
		dupe[i] = s1[i];
		i++;
	}
	dupe[i] = '\0';
	return (dupe);
}

int	ft_countdigits(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	if (n == 0)
		count = 1;
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ansbuilder(unsigned int nbr, char *ans, int len)
{
	ans[len] = '\0';
	while (--len >= 0)
	{
		ans[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (ans);
}

char	*ft_itoa(int n)
{
	int				len;
	int				neg;
	unsigned int	nbr;
	char			*ans;

	neg = 0;
	len = ft_countdigits(n);
	nbr = n;
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	ans = (char *)malloc(sizeof(char) * (len + 1));
	if (n < 0)
	{
		nbr = -n;
		neg = 1;
	}
	if (!ans)
		return (0);
	ansbuilder(nbr, ans, len);
	if (neg)
		ans[0] = '-';
	return (ans);
}
