/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 15:07:11 by hulamy            #+#    #+#             */
/*   Updated: 2020/03/10 15:24:14 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** if any character of the character set is found in s
** return a pointer to the first found, else return 0
*/

#include "libft.h"

char	*ft_strchrset(const char *s, const char *set)
{
	int		i;

	i = 0;
	while (set[i] != '\0')
	{
		if (ft_strchr(s, set[i]) != NULL)
			return ((char *)set + i);
		i++;
	}
	return (NULL);
}
