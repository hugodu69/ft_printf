/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 22:36:50 by hulamy            #+#    #+#             */
/*   Updated: 2020/03/12 22:36:56 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	take an unsigned integer and give a string
*/

/*
**	#include <stdio.h>	// for printf
**	#include <stdlib.h>	// for atoi
**
**	char			*ft_utoa(unsigned long int n);
**
**	int	main(int ac, char **av)
**	{
**		if (ac == 0)
**			return (0);
**		else if (ac == 2)
**			printf("%s\n",ft_utoa(atoi(av[1])));
**		else
**		{
**			unsigned long int i;
**			i = 0;
**			printf("  %lu\n  %s\n\n",i,ft_utoa(i));
**			i = 237683;
**			printf("  %lu\n  %s\n\n",i,ft_utoa(i));
**			i = 1234567;
**			printf("  %lu\n  %s\n\n",i,ft_utoa(i));
**			i = 12345678;
**			printf("  %lu\n  %s\n\n",i,ft_utoa(i));
**			i = 2147483646;
**			printf("  %lu\n  %s\n\n",i,ft_utoa(i));
**			i = 2147483647;
**			printf("  %lu\n  %s\n\n",i,ft_utoa(i));
**			i = 2147483648;
**			printf("  %lu\n  %s\n\n",i,ft_utoa(i));
**			i = 2147483649;
**			printf("  %lu\n  %s\n\n",i,ft_utoa(i));
**			i = 9223372036854775807;
**			printf("| %lu\n| %s\n\n",i,ft_utoa(i));
**		}
**		return 0;
**	}
*/

#include "libft.h"

char			*ft_utoa(unsigned long int n)
{
	char				*str;
	int					len;
	unsigned long int	cpy;

	cpy = n;
	len = 1;
	while (n /= 10)
		len++;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	str[--len] = cpy % 10 + '0';
	while (cpy /= 10)
		str[--len] = cpy % 10 + '0';
	return (str);
}
