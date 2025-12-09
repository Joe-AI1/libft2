/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krijooyc <krijooyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 16:42:32 by krijooyc          #+#    #+#             */
/*   Updated: 2025/12/08 21:37:16 by krijooyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

float average(int n, ...){
	va_list ap;
	int total;
	int i;

	va_start(ap, n); //va_start initialise vector
	total = 0;
	i = 0;
	while (i < n){
		total += va_arg(ap, int); // int for detect only int and va_arg Take the next argument
		++i;
	}
	va_end(ap);
	return (float)total / n;
	
	
}

int main()
{
	printf("The average is %.2f\n",
		average(5,               3, 4, 5, 6,78);
		printf("Hello %s, today is %d\n", "John", 27);
		int printf(const char *, ...);
	)
}
