/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:21:44 by hulamy            #+#    #+#             */
/*   Updated: 2019/11/19 15:23:17 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** allocate size byte of memory and return a pointer to the allocated memory
*/

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*tmp;

	if (!size || !(tmp = malloc(size)))
		return (NULL);
	ft_bzero(tmp, size);
	return (tmp);
}
