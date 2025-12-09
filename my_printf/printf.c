/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krijooyc <krijooyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:50:37 by krijooyc          #+#    #+#             */
/*   Updated: 2025/11/22 22:35:18 by krijooyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

int	print_char(int c)
{
	return write(1, &c, 1);
}

int	print_str(char *str)
{
	int count;
	
	count = 0;
	while (*str != '\0')
	{
		print_char((int)*str);
		++count;
		++str;
	}
	return count; 
}

int print_digit(long n, int base)
{
	int	count;
	char *symbols;

	symbols = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return print_digit(-n, base) + 1; //+1 for skip minus symbol "-"
	}
	if (n < base)
		return print_char(symbols[n]);
	else
	{
		count = print_digit(n / base, base); // got the loop in this line untill the last
		return count + print_digit(n % base, base);
	}
}

int print_format(char specifier, va_list ap)
{
	int count;

	count = 0;
	if (specifier == 'c')
		count = print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (specifier == 'd')
		count += print_digit((long)(va_arg(ap, int)), 10);
	else if (specifier == 'x')
		count += print_digit((long)(va_arg(ap, unsigned int)), 16);//use unsigned cause when got -1 it will go ffffff
	else
		count += write(1, &specifier, 1);
	return count;
}

int my_printf(const char *format, ...)
{
	va_list ap;
	int	count;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return count;
}

int	main()
{
	int count;
	
	my_printf("Hello %s, today is %d, in hex %x, char->%c\n",
		"John",
		27,
		27,
		'z');

	// count = my_printf("Hex: %x\n", 0);
	// my_printf("the chars  written are %d\n", count);
	// count = printf("Hex: %x\n", 0);
	// my_printf("The chars written are %d\n", count);
}