/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:24:51 by hulamy            #+#    #+#             */
/*   Updated: 2019/11/25 15:25:09 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	copy string until character is found and place cursor in dst
**	after last byte copied
*/

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*sourc;
	size_t			i;

	i = -1;
	dest = (unsigned char *)dst;
	sourc = (unsigned char *)src;
	while (++i < n)
	{
		dest[i] = sourc[i];
		if (sourc[i] == (unsigned char)c)
			return (dst + i + 1);
	}
	return (NULL);
}
