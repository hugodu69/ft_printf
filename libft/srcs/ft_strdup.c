/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:56:54 by hulamy            #+#    #+#             */
/*   Updated: 2019/11/25 13:56:55 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** save a copy of string src by allocating memory and return pointer to copy
*/

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*str;

	i = 0;
	while (src[i] != '\0')
		i++;
	if (!(str = (char*)malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	while (i-- >= 0)
		str[i + 1] = src[i + 1];
	return (str);
}
