/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elwilks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 22:54:43 by elwilks           #+#    #+#             */
/*   Updated: 2025/12/03 22:54:45 by elwilks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *string, ...);
int	ft_putchar(char c);
int	ft_putnbr(long nb);
int	ft_putnbr_hexa(unsigned long nbr, char up);
int	ft_putptr(void *ptr);
int	ft_putstr(char *string);

#endif
