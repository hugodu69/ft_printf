/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:56:16 by hulamy            #+#    #+#             */
/*   Updated: 2019/12/01 14:54:14 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** copy n characters from src to dst and return dst
*/

/*
**	#include <libc.h>
**
**	void	*ft_memcpy(void *dst, const void *src, size_t n);
**
**	int		main(int ac, char **av)
**	{
**		if (ac == 4)
**			printf("%s\n", ft_memcpy(av[1], av[2], atoi(av[3])));
**		return (0);
**	}
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*ptr;
	char	*ptr2;

	i = -1;
	ptr = (char *)dst;
	ptr2 = (char *)src;
	if (dst == src)
		return (dst);
	while (++i < (int)n)
		ptr[i] = ptr2[i];
	return (dst);
}
