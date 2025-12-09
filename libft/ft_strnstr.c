/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krijooyc <krijooyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:46:18 by krijooyc          #+#    #+#             */
/*   Updated: 2025/10/03 18:42:10 by krijooyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;

	i = 0;
	k = ft_strlen(little);
	l = len;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] && l--)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			if (big[i + j] == little[k - 1] && little[j + 1] == little[k])
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
