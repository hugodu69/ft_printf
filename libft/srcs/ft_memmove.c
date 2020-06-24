/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:56:25 by hulamy            #+#    #+#             */
/*   Updated: 2019/12/10 23:53:40 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** copy n characters from src to dst in a non destructive way and return dst
*/

/*
**	#include <libc.h>
**
**	size_t		ft_strlen(const char *str)
**	{
**		size_t i;
**
**		i = 0;
**		while (str[i])
**			i++;
**		return (i);
**	}
**
**	void	*ft_memmove(void *dst, const void *src, size_t len);
**
**	//int		main(int ac, char **av)
**	int		main(void)
**	{
**		char *src = "this is a good nyancat !\r\n";
**		char dst[0xF0];
**		int  size = strlen(src);
**
**	//	if (ac == 4)
**	//		printf("%s\n", ft_memmove(av[1], av[2], atoi(av[3])));
**
**		ft_memmove(dst, src, size);
**		printf("%s", dst);
**		return (0);
**	}
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*cpsrc;
	char	*cpdst;

	i = -1;
	cpsrc = (char *)src;
	cpdst = (char *)dst;
	if (dst == src)
		return (dst);
	if (cpsrc < cpdst)
		while (len--)
			cpdst[len] = cpsrc[len];
	else
		while (++i < len)
			cpdst[i] = cpsrc[i];
	return (dst);
}
