/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krijooyc <krijooyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:45:17 by krijooyc          #+#    #+#             */
/*   Updated: 2025/10/03 16:45:31 by krijooyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*a;
	unsigned char		b;
	size_t				i;

	a = (const unsigned char *)s;
	b = (unsigned char)c;
	if (!a)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (a[i] == b)
			return ((void *) a + i);
		i++;
	}
	return (NULL);
}
