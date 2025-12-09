/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarnpan <nkarnpan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 16:10:09 by marvin            #+#    #+#             */
/*   Updated: 2025/10/02 21:57:18 by nkarnpan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_x(unsigned long n)
{
	unsigned long	a;
	unsigned long	b;
	int				count;

	a = n % 16;
	b = n / 16;
	count = 0;
	if (b > 15)
		count += ft_putnbr_x(b);
	else if (b <= 15 && b > 0)
	{
		b = "0123456789abcdef"[b];
		count += ft_putchar(b);
	}
	a = "0123456789abcdef"[a];
	count += ft_putchar(a);
	return (count);
}

int	ft_p(void *p)
{
	unsigned long	new_p;
	int				count;

	if (p == NULL)
		return (ft_putstr("(nil)"));
	count = 0;
	new_p = (unsigned long) p;
	count += ft_putstr("0x");
	count += ft_putnbr_x((unsigned long) new_p);
	return (count);
}

// int main()
// {
// 	int a = 2297;
// 	int b;
// 	// ft_p(&a);
// 	b = ft_p(&a);
// 	// printf("\n%p\n", &a);
// 	// printf("%d --->>> ", b);
// }
// #include <stdio.h>
// #include <limits.h>

// int main()
// {
// 	printf(" %ld %ld \n", LONG_MIN, LONG_MAX);
// 	printf(" %lu %lu \n", ULONG_MAX, -ULONG_MAX);
// 	ft_printf(" %p %p \n", LONG_MIN, LONG_MAX);
// 	ft_printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
// }