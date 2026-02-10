/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:50:37 by krijooyc          #+#    #+#             */
/*   Updated: 2026/02/06 10:38:39 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

#define HEXUP "0123456789ABCDEF"
#define HEx "0123456789abcdef"

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

int print_digit(long n, int base, char *sym)
{
	int	count;
	char *symbols;

	symbols = sym;
	if (n < 0)
	{
		write(1, "-", 1);
		return print_digit(-n, base, symbols) + 1; //+1 for skip minus symbol "-"
	}
	if (n < base)
		return print_char(symbols[n]);
	else
	{
		count = print_digit(n / base, base, symbols); // got the loop in this line untill the last
		return count + print_digit(n % base, base, symbols);
	}
}

int print_pointer(int n) // must (void *p)
{
	int* p;
	unsigned long add;

	p = &n;
	add = (unsigned long)p;

	print_char('0');
	print_char('x');
	return 2 + print_digit(add, 16, HEx);
}

int print_format(char specifier, va_list ap)
{
	int count;

	count = 0;
	if (specifier == 'c')
		count = print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit((long)(va_arg(ap, int)), 10, HEx);
	else if (specifier == 'x')
		count += print_digit((long)(va_arg(ap, unsigned int)), 16, HEx);//use unsigned cause when got -1 it will go ffffff
	else if (specifier == 'u')
		count += print_digit((long)(va_arg(ap, unsigned int)), 10, HEx);
	else if (specifier == '%')
		count += print_char('%');
	else if (specifier == 'X')
		count += print_digit((long)(va_arg(ap, unsigned int)), 16, HEXUP);
	else if (specifier == 'p')
		count += print_pointer((long)(va_arg(ap, unsigned long))); // it dont have 0x fron HEX and in printf %p can;t haddle  int values at least type (void*)int -> 0xHex of the int
	else
		count += write(1, &specifier, 1);
	return count;
}

int my_printf(const char *format, ...)
{
	va_list ap;
	int	count;
	// const int something = 1;

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
	// int count;
	
	// my_printf("Hello %p, today is %d, in hex %X, char->%c\n",
	// 	"John",
	// 	27,
	// 	27,
	// 	'z');
	// printf("Hello %p, today is %d, in hex %X, char->%c\n",
	// 	"John",
	// 	27,
	// 	27,
	// 	'z');
	// my_printf("Hello %p, today is %d, in hex %X, char->%c\n", "John", 27, 27, 'z');
	// printf("Hello %p, today is %d, in hex %X, char->%c\n", "John", 27, 27, 'z');
	my_printf("Hello %p, today is %d, in hex %X, char->%c\n", 42, 27, 27, 'z');
	printf("Hello %p, today is %d, in hex %X, char->%c\n", 42, 27, 27, 'z');
	printf("%p\n", (void*)42);
	my_printf("%p\n", (void*)42);


	// count = my_printf("Hex: %x\n", 0);
	// my_printf("the chars  written are %d\n", count);
	// count = printf("Hex: %p\n", "happ");
	// my_printf("The chars written are %d\n", count);
}
