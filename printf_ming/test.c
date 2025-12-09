/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krijooyc <krijooyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 23:20:37 by krijooyc          #+#    #+#             */
/*   Updated: 2025/10/02 23:28:45 by krijooyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
int	main(void)
{
	printf("\nFake %d\n", ft_printf(NULL));
	printf("\nReal %d\n", printf(NULL));
	return (0);
}
