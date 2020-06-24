/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 22:41:54 by hulamy            #+#    #+#             */
/*   Updated: 2019/12/13 01:35:15 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** return an array of string with each word found in str, with c as separator
*/

/*
**	#include <stdio.h>
**	#include <stdlib.h>
**	#include <unistd.h>
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
**	char	*ft_substr(char const *s, unsigned int start, size_t len)
**	{
**		char	*str;
**		size_t	i;
**
**		if (!s)
**			return (NULL);
**		if (ft_strlen(s) < start)
**			return ("");
**		if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
**			return (NULL);
**		i = 0;
**		while (i < len && s[start])
**			str[i++] = s[start++];
**		str[i] = '\0';
**		return (str);
**	}
**
**	char		**ft_split(char const *s, char c);
**	char		**ft_strsplit(char const *s, char c);
**
**	int		main(void)
**	{
**		char	**str;
**		int		i;
**
**		char	*s;
**		char	c;
**
**		i = -1;
**		s = NULL;
**		c = ' ';
**		str = ft_split(s, c);
**		//if (str)
**		//{
**			printf("s    : '%s'\n", s);
**			printf("*str : '%p'\n", str[0]);
**			while (str[++i])
**				printf("str[%i] : '%s'\n", i, str[i]);
**		//}
**		return (0);
**	}
*/

#include "libft.h"

static int	count(char const *s, char c)
{
	int		i;
	int		words;

	i = -1;
	words = 0;
	while (s[++i] != '\0')
		if (s[i] != c && ++words)
			while (s[i + 1] != '\0' && s[i + 1] != c)
				i++;
	return (words);
}

void		*ft_free(char **array, int w)
{
	int i;

	i = 0;
	while (array[i] != NULL && i < w)
		free(array[i++]);
	free(array);
	return (NULL);
}

char		**empty_s(char **empty)
{
	if (!(empty = (char **)malloc(sizeof(char *) * 1)))
		return (NULL);
	empty[0] = NULL;
	return (empty);
}

char		**ft_split(char const *s, char c)
{
	char	**array;
	int		w;
	int		len;

	if (!s)
		return (empty_s(NULL));
	if (!(array = (char **)malloc(sizeof(char *) * (count(s, c) + 1))))
		return (NULL);
	w = 0;
	while (*s != '\0')
	{
		len = 0;
		if (*s != c)
		{
			while (s[len] != '\0' && s[len] != c)
				len++;
			if (!(array[w++] = ft_substr(s, 0, len)))
				return (ft_free(array, w));
			s += len - 1;
		}
		s++;
	}
	array[w] = NULL;
	return (array);
}
