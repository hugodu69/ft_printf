/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:59:01 by hulamy            #+#    #+#             */
/*   Updated: 2020/02/19 15:44:04 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	take an integer and give a string
*/

/*
**	#include <stdio.h>	// for printf
**	#include <stdlib.h>	// for atoi
**
**	char			*ft_itoa(long int n);
**
**	int	main(int ac, char **av)
**	{
**		if (ac == 0)
**			return (0);
**		else if (ac == 2)
**			printf("%s\n",ft_itoa(atoi(av[1])));
**		else
**		{
**			long int i;
**			i = 0;
**			printf("  %li\n  %s\n\n",i,ft_itoa(i));
**			i = 1234567;
**			printf("  %li\n  %s\n\n",i,ft_itoa(i));
**			i = -1234567;
**			printf("  %li\n  %s\n\n",i,ft_itoa(i));
**			i = 237683;
**			printf("  %li\n  %s\n\n",i,ft_itoa(i));
**			i = 2147483647;
**			printf("| %li\n| %s\n\n",i,ft_itoa(i));
**			i = i ^ 0;	// create the opposite of a signed '0', which
**						// is 0 followed by 31 '1', the signed int max
**			printf("* %li\n* %s\n\n",i,ft_itoa(i));
**			i = i ^ 0;
**			i = 1 << 31;	// change the most lefted bit from '0' (positive)
**							// to '1' (negative), the signed int min
**			printf("* %li\n* %s\n\n",i,ft_itoa(i));
**			i = 2147483646;
**			printf("  %li\n  %s\n\n",i,ft_itoa(i));
**			i = -2147483648;
**			printf("| %li\n| %s\n\n",i,ft_itoa(i));
**			i = -2147483647;
**			printf("  %li\n  %s\n\n",i,ft_itoa(i));
**			i = 2147483648;
**			printf("  %li\n  %s\n\n",i,ft_itoa(i));
**			i = -2147483649;
**			printf("  %li\n  %s\n\n",i,ft_itoa(i));
**			i = 9223372036854775807;
**			printf("| %li\n| %s\n\n",i,ft_itoa(i));
**			i = -9223372036854775807;
**			printf("| %li\n| %s\n\n",i,ft_itoa(i));
**		}
**		return 0;
**	}
*/

#include "libft.h"

char			*ft_itoa(long int n)
{
	char		*str;
	int			len;
	long int	cpy;
	char		rgt;

	cpy = (n < 0) ? (n / 10) * -10 : (n / 10) * 10;
	len = (n < 0) ? 2 : 1;
	rgt = (n < 0) ? (n % 10) * -1 + '0' : n % 10 + '0';
	while (n /= 10)
		len++;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	str[--len] = rgt;
	while (cpy /= 10)
		str[--len] = cpy % 10 + '0';
	if (len)
		str[0] = '-';
	return (str);
}
