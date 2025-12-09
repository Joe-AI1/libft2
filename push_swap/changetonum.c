/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changetonum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pukchayn <pukchayn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 21:08:03 by pukchayn          #+#    #+#             */
/*   Updated: 2025/10/14 18:15:42 by pukchayn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	checkifneg(char *s)
{
	size_t	i;
	int		a;

	a = 0;
	i = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] >= '0' && s[i] <= '9')
			a = 1;
		if (s[i] == '-' && a == 0)
			return (-1);
		i++;
	}
	return (1);
}

int	check(char nptr, int num, int b)
{
	if ((nptr == ' ' || nptr == '\t' || nptr == '\n'
			|| nptr == '\r' || nptr == '\v' || nptr == '\f'
			|| nptr == '-' || nptr == '+') && num == 0 && b < 1)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		num;
	size_t	i;
	int		box;
	int		b;

	i = 0;
	box = 0;
	num = 0;
	b = 0;
	if (!nptr)
		return (0);
	while (i < ft_strlen((char *)nptr) && (check((char)nptr[i], box, b) == 1
			|| (nptr[i] >= '0' && nptr[i] <= '9')) && b < 2)
	{
		if ((nptr[i] == '-' || nptr[i] == '+'))
			b++;
		if (nptr[i] >= '0' && nptr[i] <= '9')
		{
			box = 1;
			num *= 10;
			num += (nptr[i] - 48);
		}
		i++;
	}
	return (num * checkifneg((char *)nptr));
}

long int	ft_atoilong(const char *nptr)
{
	long int	num;
	size_t		i;
	int			box;
	int			b;

	i = 0;
	box = 0;
	num = 0;
	b = 0;
	if (!nptr)
		return (0);
	while (i < ft_strlen((char *)nptr) && (check((char)nptr[i], box, b) == 1
			|| (nptr[i] >= '0' && nptr[i] <= '9')) && b < 2)
	{
		if ((nptr[i] == '-' || nptr[i] == '+'))
			b++;
		if (nptr[i] >= '0' && nptr[i] <= '9')
		{
			box = 1;
			num *= 10;
			num += (nptr[i] - 48);
		}
		i++;
	}
	return (num * checkifneg((char *)nptr));
}
