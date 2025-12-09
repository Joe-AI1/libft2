/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krijooyc <krijooyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:46:56 by krijooyc          #+#    #+#             */
/*   Updated: 2025/10/03 17:17:27 by krijooyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		base;
	int		num;

	i = 0;
	base = 1;
	num = 0;
	while (str[i] != '\0')
	{
		while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		if (str[i] == 45 || str[i] == 43)
		{
			if (str[i] == 45)
				base *= -1;
			i++;
		}
		while (ft_isdigit(str[i]))
			num = num * 10 + (str[i++] - 48);
		return (num * base);
	}
	return (0);
}
