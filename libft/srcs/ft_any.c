/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:14:49 by hulamy            #+#    #+#             */
/*   Updated: 2018/11/16 15:14:53 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_any(char **tab, int (*f)(char*))
{
	int i;

	i = -1;
	if (!tab)
		return (0);
	while (tab[++i])
		if (f(tab[i]) == 1)
			return (1);
	return (0);
}
