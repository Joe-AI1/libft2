#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#define HEXUP "0123456789ABCDEF"
#define HEXLOW "0123456789abcdef"
#define DEC "0123456789"

int	print_char(int c)
{
	return write(1, &c, 1);
}

int	print_str(char *str)
{
	int count;
	
	count = 0;
	if (!str)
		str = "(null)";
	while (*str != '\0')
	{
		print_char((int)*str);
		++count;
		++str;
	}
	return count; 
}

/* ** 1. Generic function for Unsigned numbers (Hex, Unsigned Int, Pointers) 
** It does NOT handle negative signs.
*/
int print_digit_base(unsigned long n, char *base_symbols)
{
	unsigned long	base;
	int				count;

	base = 0;
	while (base_symbols[base])
		base++;
	count = 0;
	if (n >= base)
		count += print_digit_base(n / base, base_symbols);
	count += print_char(base_symbols[n % base]);
	return (count);
}

/* ** 2. Function for Signed Integers (%d, %i)
** It handles the negative sign, then calls the base printer.
*/
int print_digit_signed(long n)
{
	int count;

	count = 0;
	if (n < 0)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	count += print_digit_base((unsigned long)n, DEC);
	return (count);
}

/* ** 3. Pointer function
** Handles the 0x prefix and nil case.
*/
int print_pointer(unsigned long n)
{
	int count;

	// Handle NULL pointer case specifically for your system (usually (nil))
	if (n == 0)
		return (print_str("(nil)")); 
	
	count = 0;
	count += print_str("0x");
	count += print_digit_base(n, HEXLOW);
	return (count);
}

int print_format(char specifier, va_list ap)
{
	int count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += print_str(va_arg(ap, char *));
	// For %d and %i, we use the SIGNED function
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit_signed((long)(va_arg(ap, int)));
	// For %u, %x, %X, we use the UNSIGNED function with different bases
	else if (specifier == 'u')
		count += print_digit_base((unsigned long)(va_arg(ap, unsigned int)), DEC);
	else if (specifier == 'x')
		count += print_digit_base((unsigned long)(va_arg(ap, unsigned int)), HEXLOW);
	else if (specifier == 'X')
		count += print_digit_base((unsigned long)(va_arg(ap, unsigned int)), HEXUP);
	else if (specifier == 'p')
		count += print_pointer((unsigned long)(va_arg(ap, void *)));
	else if (specifier == '%')
		count += print_char('%');
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
	// Correct way to test pointer printing: Use (void *) cast
	printf("REAL: Hello %p\n", (void *)42);
	my_printf("MINE: Hello %p\n", (void *)42);

	printf("REAL: %d\n", -12345);
	my_printf("MINE: %d\n", -12345);
	
	printf("REAL: %x\n", -255);
	my_printf("MINE: %x\n", -255);
}