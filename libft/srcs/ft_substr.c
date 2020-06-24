/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 16:00:10 by hulamy            #+#    #+#             */
/*   Updated: 2019/12/09 22:04:26 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** create a copy of a portion of s, begining at start and of length len
*/

/*
**	#include <unistd.h>
**	#include <stdlib.h>
**	#include <stdio.h>
**
**	char	*ft_substr(char const *s, unsigned int start, size_t len);
**
**	char	*ft_strdup(const char *src)
**	{
**		int		i;
**		char	*str;
**
**		i = 0;
**		while (src[i] != '\0')
**			i++;
**		if (!(str = (char*)malloc(sizeof(*str) * (i + 1))))
**			return (NULL);
**		while (i-- >= 0)
**			str[i + 1] = src[i + 1];
**		return (str);
**	}
**
**	int		ft_strncmp(const char *s1, const char *s2, size_t n)
**	{
**		size_t	i;
**		int		res;
**
**		i = 0;
**		res = 0;
**		while (s1[i] && s1[i] == s2[i] && i < n - 1)
**			i++;
**		if (n != 0)
**			res = (unsigned char)s1[i] - (unsigned char)s2[i];
**		return (res);
**	}
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
**	int		main(int ac, char **av)
**	{
**		char	*str;
**		size_t	size;
**		int		start;
**
**		str = "frgehr";
**		start = 2;
**		size = 5;
**		if (ac == 4)
**		{
**			str = strdup(av[1]);
**			start = atoi(av[2]);
**			size = atoi(av[3]);
**		}
**		char	*ret = ft_substr(str, start, size);
**		printf("%s, %i, %zu\n", str, start, size);
**		printf("%s\n", ret);
**		free(ret);
**		return (0);
**	}
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len && s[start])
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
