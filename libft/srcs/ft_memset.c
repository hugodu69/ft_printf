/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:56:37 by hulamy            #+#    #+#             */
/*   Updated: 2019/11/25 13:56:38 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** copy n time a character in a string and return the string
*/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)b;
	i = 0;
	while (i < len)
		ptr[i++] = c;
	return (b);
}
