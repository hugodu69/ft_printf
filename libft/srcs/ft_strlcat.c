/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:57:02 by hulamy            #+#    #+#             */
/*   Updated: 2019/11/25 14:23:18 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	append src to sized dest and return size of final dest
*/

/*
**	#include <libc.h>
**
**	size_t	ft_strlcat(char *dest, const char *src, size_t size);
**
**	size_t ft_strlcat2(char *dest, char *src, size_t size);
**
**	int ft_strlen(char *str)
**	{
**		int i;
**
**		i = 0;
**		while (str[i])
**			i++;
**		return (i);
**	}
**
**	int		main(int ac, char **av)
**	{
**		char tmp1[100];
**		char tmp2[100];
**		int i;
**
**		i = atoi(av[3]);
**		strcpy(tmp1, av[1]);
**		strcpy(tmp2, av[2]);
**
**		if (ac == 4)
**		{
**			printf("----strlcat: %zu - %s - %s\n", strlcat(tmp1, tmp2, i),
**																tmp1, tmp2);
**
**			strcpy(tmp1, av[1]);
**			strcpy(tmp2, av[2]);
**
**			printf("-ft_strlcat: %zu - %s - %s\n", ft_strlcat(tmp1, tmp2, i),
**																tmp1, tmp2);
**
**			strcpy(tmp1, av[1]);
**			strcpy(tmp2, av[2]);
**
**			printf("ft_strlcat2: %zu - %s - %s\n", ft_strlcat2(tmp1, tmp2, i),
**																tmp1, tmp2);
**		}
**	}
**
**	size_t ft_strlcat2(char *dest, char *src, size_t size)
**	{
**		size_t i;
**		size_t dest_length;
**		size_t src_length;
**
**		i = 0;
**		dest_length = ft_strlen(dest);
**		src_length = ft_strlen(src);
**		if (size > dest_length + 1)
**		{
**			while (i < (size - dest_length - 1))
**			{
**				dest[i + dest_length] = src[i];
**				i++;
**			}
**			dest[dest_length + i] = '\0';
**		}
**		if (size >= dest_length)
**			return (dest_length + src_length);
**		return (src_length + size);
**	}
*/

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (dest[i] && i < size)
		i++;
	while (src[j])
	{
		if (j + i < size - 1 && size)
		{
			dest[i + j] = src[j];
			dest[i + j + 1] = '\0';
		}
		j++;
	}
	return (i + j);
}
