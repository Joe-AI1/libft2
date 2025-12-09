/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elwilks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 22:54:29 by elwilks           #+#    #+#             */
/*   Updated: 2025/12/03 22:54:30 by elwilks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conversion(const char type, va_list vargs)
{
	if (type == 'c')
		return (ft_putchar(va_arg(vargs, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(vargs, char *)));
	else if (type == 'p')
		return (ft_putptr(va_arg(vargs, void *)));
	else if ((type == 'd') || (type == 'i'))
		return (ft_putnbr(va_arg(vargs, int)));
	else if (type == 'u')
		return (ft_putnbr(va_arg(vargs, unsigned int)));
	else if ((type == 'x') || (type == 'X'))
		return (ft_putnbr_hexa(va_arg(vargs, unsigned int), type));
	else if (type == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *string, ...)
{
	va_list	vargs;
	int		len;
	int		check;

	va_start(vargs, string);
	len = 0;
	while (*string)
	{
		if (*string == '%')
		{
			check = ft_conversion(*(++string), vargs);
			if (check == -1)
				return (-1);
			len += check;
		}
		else
		{
			if (write(1, string, 1) == -1)
				return (-1);
			len++;
		}
		string++;
	}
	va_end(vargs);
	return (len);
}
