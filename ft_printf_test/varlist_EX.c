/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varlist_EX.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krijooyc <krijooyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:35:28 by krijooyc          #+#    #+#             */
/*   Updated: 2025/11/22 21:57:39 by krijooyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int sum(int count, ...){ // "..." variable arguments (you can pass any number of ints). and in sum{} must atleast 1 parameter describe so ... not the parameter
	va_list args;
	va_start(args, count); // strat reading extra argument after reading "count" argument

	int s = 0;
	int i;
	for (i = 0; i < count; i++){
		int x = va_arg(args, int);
		s += x;
	}
	va_end(args);
	return s;
}

int sum2(int a, ...){
	va_list args;
	va_start(args, a);
	
	int s = a;
	int i;
	int x = va_arg(args, int);

	while(x != 0){ //it for detect Null beware If it detect 0 it will count Null and stop
		s += x;
		x = va_arg(args, int);
	}
	va_end(args);
	return s;
} 

// int main(int argc, char *argv[]){
// 	printf("Sum is %d\n", sum(1, 2, 3, 4));
// 	return 0;
// }

int main(){
	printf("Sum is %d\n", sum(5, 2, 3, 4, 5, 6));
	return 0;
}