/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:01:49 by hulamy            #+#    #+#             */
/*   Updated: 2019/12/09 21:46:54 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	create a copy of s without the firsts and lasts set of characters
*/

/*
**	#include <libc.h>
**
**	char	*ft_substr(char const *s, unsigned int start, size_t len)
**	{
**		char	*str;
**		size_t	i;
**
**		if (!s)
**			return (NULL);
**		if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
**			return (NULL);
**		str[len] = '\0';
**		i = 0;
**		while (i < len)
**			str[i++] = s[start++];
**		return (str);
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
**	char	*ft_strchr(const char *s, int c)
**	{
**		int	i;
**		int	j;
**
**		i = 0;
**		j = -1;
**		while (s[i])
**			i++;
**		while (++j < i + 1)
**			if (s[j] == c)
**				return ((char *)s + j);
**		return (NULL);
**	}
**
**	char	*ft_strtrim(char const *s1, char const *set);
**
**	int		main(int ac, char **av)
**	{
**		char	*s1;
**		char	*s2;
**
**		if (ac == 3)
**		{
**			s1 = strdup(av[1]);
**			s2 = strdup(av[2]);
**		}
**		if (ac == 1)
**		{
**			s1 = "fuehf";
**			s2 = NULL;
**		}
**			printf("%s\n",ft_strtrim(s1, s2));
**		return (0);
**	}
*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	while (s1[0] && ft_strchr(set, s1[0]))
		s1++;
	len = ft_strlen(s1) - 1;
	while (len >= 0 && ft_strchr(set, s1[len]))
		len--;
	len++;
	if (!(str = ft_substr(s1, 0, len)))
		return (NULL);
	return (str);
}
