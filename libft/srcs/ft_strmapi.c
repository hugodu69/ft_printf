/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:01:40 by hulamy            #+#    #+#             */
/*   Updated: 2019/12/09 21:44:07 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	create a new array with the result of function f on every element of
**	s by index i
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
**	char	touppercase(unsigned int i, char c)
**	{
**		if (i < 3 && c >= 'a' && c <= 'z')
**			c -= 32;
**		return (c);
**	}
**
**	char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
**
**	int		main(int ac, char **av)
**	{
**		char	*str;
**		char	touppercase(unsigned int, char);
**
**		if (ac > 2)
**			return (0);
**		if (ac == 2)
**		str = strdup(av[1]);
**		if (ac == 1)
**			str = NULL;
**		//str = ft_strmapi(str, touppercase);
**		str = ft_strmapi(str, NULL);
**		printf("%s\n",str);
**		return (0);
**	}
*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;
	int		size;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	i = -1;
	while (s[++i])
		str[i] = f(i, s[i]);
	return (str);
}
