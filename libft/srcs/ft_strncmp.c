/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:57:59 by hulamy            #+#    #+#             */
/*   Updated: 2019/11/25 13:58:00 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** compare size first character of two null terminated strings
** and return value of difference between first two different character
*/

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		res;

	i = 0;
	res = 0;
	while (s1[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	if (n != 0)
		res = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (res);
}
