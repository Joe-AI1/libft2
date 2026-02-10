#ifdef MY_PRINTF_H
# define MY_PRINTF_H   

# include <stdarg.h>
# include <unistd.h>

int	print_char(int c);
int	print_str(char *str);
int print_digit_base(unsigned long n, char *base_symbols);
int print_digit_signed(long n);
int print_pointer(unsigned long n);
int print_format(char specifier, va_list ap);
int	my_printf(const char *format, ...);

#endif