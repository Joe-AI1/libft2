/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varlist_Ex2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krijooyc <krijooyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 15:09:03 by krijooyc          #+#    #+#             */
/*   Updated: 2025/11/22 16:49:21 by krijooyc         ###   ########.fr       */
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
	va_end(ap); //Cleans up the va_list object
	return (float)total / n;
	
	
}

int sum_chars(int count, ...) {
    va_list args;
    va_start(args, count);

    int s = 0;
    for (int i = 0; i < count; i++) {
        int x = va_arg(args, int); // char becomes int
        s += x;
    }

    va_end(args);
    return s;
}

void print_chars(int count, ...) {
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++) {
        char c = (char)va_arg(args, int); // read as int, cast to char
        printf("%c ", c);
    }

    va_end(args);
}


int main(){
	float average_age;
	
	average_age = average(3, 10, 15, 20);
	printf("The average age of those 3 people is %f\n", average_age);
	return 0;
}
