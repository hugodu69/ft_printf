/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:04:09 by hulamy            #+#    #+#             */
/*   Updated: 2020/02/27 18:06:44 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** create a new string size of str1 + str2
** fill it with concated str1 and str2m as "str1str2"
** free the received strings str1 and str2
** return the new string
*/

/*
**	#include <stdio.h>
**	#include "libft.h"
**
**	char	*ft_concat_free(char *str1, char *str2);
**
**	int		main(int ac, char **av)
**	{
**		if (ac != 3)
**			return (0);
**		printf("%s\n", ft_concat_free(ft_strdup(av[1]), ft_strdup(av[2])));
**		return (0);
**	}
*/

#include "libft.h"

char	*ft_concat_free(char *str1, char *str2)
{
	char	*cat;
	int		i;
	int		j;

	cat = ft_memalloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	i = -1;
	j = 0;
	while (str1[++i])
		cat[i] = str1[i];
	while (str2[j])
		cat[i++] = str2[j++];
	free(str1);
	free(str2);
	return (cat);
}
