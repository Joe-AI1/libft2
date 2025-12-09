/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krijooyc <krijooyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:25:30 by marvin            #+#    #+#             */
/*   Updated: 2025/10/02 23:26:24 by krijooyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *s)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
		count++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	long		a;
	long		b;
	int			count;
	long		num;

	count = 0;
	num = n;
	if (n < 0)
	{
		count += ft_putchar('-');
		num = -num;
	}
	a = num % 10;
	b = num / 10;
	if (b > 9)
		count += ft_putnbr(b);
	else if (b <= 9 && b > 0)
	{
		b = b + '0';
		count += ft_putchar(b);
	}
	a = a + '0';
	count += ft_putchar(a);
	return (count);
}

int	ft_putnbr_u(unsigned int n)
{
	unsigned int	a;
	unsigned int	b;
	int				count;

	count = 0;
	a = n % 10;
	b = n / 10;
	if (b > 9)
		count += ft_putnbr_u(b);
	else if (b <= 9 && b > 0)
	{
		b = b + '0';
		count += ft_putchar(b);
	}
	a = a + '0';
	count += ft_putchar(a);
	return (count);
}

int	ft_putnbr_sx(unsigned int n)
{
	unsigned int	a;
	unsigned int	b;
	int				count;

	a = n % 16;
	b = n / 16;
	count = 0;
	if (b > 15)
		count += ft_putnbr_sx(b);
	else if (b <= 15 && b > 0)
	{
		b = "0123456789ABCDEF"[b];
		count += ft_putchar(b);
	}
	a = "0123456789ABCDEF"[a];
	count += ft_putchar(a);
	return (count);
}

// int main()
// {
// 	int n = -2147483648 ;
// 	int a;
// 	a = ft_putnbr(n);
// 	write(1, "\n", 1);
// 	// ft_putnbr_sx(a);
// 	// printf("\n%X\n", n);
// }