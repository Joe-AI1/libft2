/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krijooyc <krijooyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:41:58 by krijooyc          #+#    #+#             */
/*   Updated: 2025/10/03 16:42:30 by krijooyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	s;
	size_t	i;

	s = ft_strlen(src);
	d = 0;
	while (d < size && dst[d])
		d++;
	if (d == size)
		return (size + s);
	i = 0;
	while (src[i] && (d + i) < size - 1)
	{
		dst[d + i] = src[i];
		i++;
	}
	if ((d + i) < size)
		dst[d + i] = '\0';
	return (d + s);
}
