/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:54:53 by hulamy            #+#    #+#             */
/*   Updated: 2019/12/01 16:04:12 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	exemple allocation for 5 integers with malloc then calloc :
**	a = (int *)malloc(5 * sizeof(int));	//5*4bytes = 20 bytes
**	free(a);
**	a = (int *)calloc(5, sizeof(int));
**
**	allocate count * size byte of memory and
**	return a pointer to the allocated memory
*/

/*
**	#include <libc.h>
**
**	void	ft_bzero(void *s, size_t n)
**	{
**		size_t			i;
**		unsigned char	*ptr;
**
**		if (n)
**		{
**			ptr = (unsigned char *)s;
**			i = 0;
**			while (i < n)
**				ptr[i++] = '\0';
**		}
**	}
**
**	void	*ft_calloc(size_t count, size_t size);
**
**	int		main(void)
**	{
**		void *str;
**
**		str = ft_calloc(0, 0);
**		if (str == ((void *)0))
**			printf("failed\n");
**		free(str);
**		return (0);
**	}
*/

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	if (!(tmp = malloc(count * size)))
		return (NULL);
	ft_bzero(tmp, count * size);
	return (tmp);
}
