/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:00:04 by hulamy            #+#    #+#             */
/*   Updated: 2019/11/25 14:00:05 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	write the string s on the given file descritor fd
*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (s && *s)
		ft_putchar_fd(*s++, fd);
}
