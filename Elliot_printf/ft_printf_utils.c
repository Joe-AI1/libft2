/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elwilks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 22:54:56 by elwilks           #+#    #+#             */
/*   Updated: 2025/12/03 22:56:19 by elwilks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(long nb)
{
	long	nbr;
	int		len;
	int		temp;

	len = 0;
	if (nb < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		len += 1;
		nb *= -1;
	}
	nbr = nb % 10 + '0';
	if (nb > 9)
	{
		temp = ft_putnbr(nb / 10);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	if (ft_putchar(nbr) == -1)
		return (-1);
	len += 1;
	return (len);
}

int	ft_putnbr_hexa(unsigned long nbr, char upcase)
{
	int		len;
	int		result;
	char	*base;
	int		temp;

	result = 0;
	len = 0;
	if (upcase == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (nbr > 15)
	{
		temp = ft_putnbr_hexa((nbr / 16), upcase);
		if (temp == -1)
			return (-1);
		len = len + temp;
	}
	result = nbr % 16;
	if (ft_putchar(base[result]) == -1)
	{
		return (-1);
	}
	len = len + 1;
	return (len);
}

int	ft_putptr(void *ptr)
{
	int	len;
	int	temp;

	len = 0;
	temp = 0;
	if (ptr == 0)
	{
		return (write(1, "(nil)", 5));
	}
	if (ft_putstr("0x") == -1)
	{
		return (-1);
	}
	len = len + 2;
	temp = ft_putnbr_hexa((unsigned long)ptr, 'x');
	if (temp == -1)
	{
		return (-1);
	}
	len = len + temp;
	return (len);
}

int	ft_putstr(char *string)
{
	int	len;

	if (!string)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	len = 0;
	while (*string != '\0')
	{
		if (ft_putchar(*string) == -1)
			return (-1);
		len++;
		string++;
	}
	return (len);
}
