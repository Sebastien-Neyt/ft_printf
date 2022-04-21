/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneyt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 09:59:46 by sneyt             #+#    #+#             */
/*   Updated: 2022/04/20 11:30:48 by sneyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

int		ft_putchar(int a);
void	ft_putstr(char *str);
int		ft_printstr(char *str);
int		ft_printnum(int num);
int		ft_numlen(unsigned int a);
char	*ft_unsitoa(unsigned int a);
int		ft_printunsnum(unsigned int a);
int		ft_hexlen(unsigned int a);
void	ft_put_hex(unsigned int a, const char format);
int		ft_printhex(unsigned int a, const char format);
int		ft_printpercent(void);
int		ft_printf(const char *str, ...);
int		ft_pointerlen(unsigned long nb);
void	ft_putpointer(unsigned long nb);
int		ft_printpointer(unsigned long ptr);

size_t	ft_strlen(char const *str);
char	*ft_strdup(char *s1);
int		ft_countdigits(int n);
char	*ansbuilder(unsigned int nbr, char *ans, int len);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);

#endif
