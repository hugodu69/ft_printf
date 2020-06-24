/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:57:19 by hulamy            #+#    #+#             */
/*   Updated: 2019/12/01 16:12:57 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	copy size - 1 length of src into dest,
**	terminate it with a '\0'
**	and return size of src
**	this way, if you try to copy a name in a variable with an available size
**	of 5 for exemple, if you use ft_strlcpy(variable, name, sizeof(variable))
**	you will know if the name was too long for the variable by looking at the
**	return value (which is size of name)
*/

/*
**	#include <libc.h>
**
**	size_t	ft_strlcpy(char *dest, const char *src, size_t size);
**
**	int		main(int argc, char **argv)
**	{
**		char str[100];
**		int i;
**		unsigned int u;
**		unsigned int v;
**
**		i = atoi(argv[3]);
**		strcpy(str, argv[2]);
**		if (argc > 3)
**		{
**			u = strlcpy(argv[2], argv[1], i);
**			printf("strlcpy   : %s - %s - %d",argv[1], argv[2], i);
**			printf(" - return:%d\n",u);
**			strcpy(argv[2], str);
**			printf("(re-init  : %s - %s - %d)\n",argv[1], argv[2], i);
**			v = ft_strlcpy(argv[2], argv[1], i);
**			printf("ft_strlcpy: %s - %s - %d",argv[1], argv[2], i);
**			printf(" - return:%d\n",v);
**		}
**		return (0);
**	}
*/

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		if (i + 1 < size)
			dest[i] = src[j++];
		i++;
	}
	if (size > 0)
		dest[j] = '\0';
	return (i);
}
