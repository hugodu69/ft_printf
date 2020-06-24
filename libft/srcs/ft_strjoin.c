/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:01:26 by hulamy            #+#    #+#             */
/*   Updated: 2019/12/09 21:38:35 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** create a new string by concatenating the two strings s1 and s2
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
**	char		*ft_strjoin(char const *s1, char const *s2);
**
**	int		main(int ac, char **av)
**	{
**		char	*s1;
**		char	*s2;
**		char	*str;
**
**		if (ac == 0)
**			return (0);
**		else if (ac == 3)
**		{
**			s1 = strdup(av[1]);
**			s2 = strdup(av[2]);
**		}
**		else
**		{
**			s1 = malloc(sizeof(char*) * 100);
**			s1 = "sdf";
**			s2 = "tref";
**		}
**		str = ft_strjoin(s1, s2);
**		printf("%s\n", str);
**		return (0);
**	}
*/

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	len = 0;
	i = 0;
	while (s1[i] != '\0')
		str[len++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		str[len++] = s2[i++];
	str[len] = '\0';
	return (str);
}
