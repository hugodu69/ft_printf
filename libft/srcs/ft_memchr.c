/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:55:51 by hulamy            #+#    #+#             */
/*   Updated: 2019/12/12 21:50:32 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** locate character in string and return its position
*/

/*
**	#include <libc.h>
**
**	void	*ft_memchr(const void *s, int c, size_t n);
**
**	int		main(void)
**	{
**		const char	*str;
**
**		char *pouet = "z";
**		char *lolzer = (char *)&pouet[2];
**		lolzer = "aaaaaaaaaa";
**		str = ft_memchr(pouet, 'a', 50);
**		if (!str)
**			printf("NULL");
**		else
**			printf("%s\n", str);
**		return (0);
**	}
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sbis;
	size_t			i;

	sbis = (unsigned char *)s;
	i = -1;
	while (++i < n)
		if (sbis[i] == (unsigned char)c)
			return ((void *)sbis + i);
	return (NULL);
}
