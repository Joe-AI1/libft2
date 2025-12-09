/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallswap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pukchayn <pukchayn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 22:24:35 by pukchayn          #+#    #+#             */
/*   Updated: 2025/12/04 01:04:51 by pukchayn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	lastthree(char **box)
{
	int	max;
	int	loc;

	max = checkmax(box);
	loc = locationchecker(box, max) + 1;
	if (loc > 2)
		shift_up(box, 0);
	else if (loc <= 2 && loc != 1)
		shift_down(box, 0);
	if (ft_atoi(box[1]) < ft_atoi(box[2]))
		swapbox(box, 0);
}

void	smallswap(char **box, int ar)
{
	if (ar == 2)
	{
		if (ft_atoi(box[0]) < ft_atoi(box[1]))
			swapbox(box, 0);
	}
}
