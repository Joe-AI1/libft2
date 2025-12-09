/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freebox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pukchayn <pukchayn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:29:09 by pukchayn          #+#    #+#             */
/*   Updated: 2025/10/15 12:53:18 by pukchayn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	freethedangbox(char **box)
{
	int	i;

	i = 0;
	if (!box)
		return ;
	while (box[i] != NULL)
	{
		free(box[i]);
		i++;
	}
	free(box);
}

int	checkifalreadydone(char **box)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (box[i] != NULL)
	{
		x = i;
		while (box[x] != NULL)
		{
			if (ft_atoi(box[i]) < ft_atoi(box[x]))
				return (1);
			x++;
		}
		i++;
	}
	return (0);
}
