/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krijooyc <krijooyc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:39:36 by krijooyc          #+#    #+#             */
/*   Updated: 2025/10/03 16:39:51 by krijooyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int c, size_t count)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)dst;
	while (count--)
		*(ptr++) = (unsigned char)c;
	return (dst);
}
