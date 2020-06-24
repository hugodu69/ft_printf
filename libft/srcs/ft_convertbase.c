/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 20:19:54 by hulamy            #+#    #+#             */
/*   Updated: 2020/02/26 20:20:14 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	take a string that is a number in a certain base
**	and convert it in another base
**	it works with unsigned long int
**	return the new string
*/

/*
**	#include <stdio.h>	// for printf
**	#include <stdlib.h>	// for atoi
**
**	char	*ft_convertbase(char *nbr, char *base_from, char *base_to);
**
**	int	main(int ac, char **av)
**	{
**		if (ac != 4)
**		{
**			printf("usage:\nchar *nbr, char *base_from, char *base_to\n");
**			printf("try the max long unsigned int : 18446744073709551615\n");
**		}
**		else
**			printf("[%s]\n",ft_convertbase(av[1], av[2], av[3]));
**		return (0);
**	}
*/

#include "libft.h"

/*
** check :
** -if the base has no characters that appear more than one time
** -if the signes '-' and '+' are not part of the set
** -if there are no invisible characters (inferior to 32 or equal to 127)
*/

int
	is_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
			if (base[i] == base[j++])
				return (0);
		if (base[i] == '-' || base[i] == '+' || base[i] < 33 || base[i] == 127)
			return (0);
		i++;
	}
	if (i >= 2)
		return (1);
	return (0);
}

/*
** check :
** -if base is valid
** -if nbr contain characters
** -if nbr is made of elements of base only
*/

int
	is_valid_nbr(char *nbr, char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!is_valid_base(base))
		return (0);
	while (nbr[i])
	{
		j = 0;
		while (base[j] && nbr[i] != base[j])
			j++;
		if (base[j] == '\0')
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

/*
** -transform a nbr written as a string into a decimal nbr
** -it's an unsigned nbr because the negativity is managed elsewhere
** -if the number is bigger than the max unsigned long int it's false
**  as it's impossible to verify if a number is bigger than the biggest
**  unsigned, we verify the difference before the multiplication
*/

unsigned long int
	base_to_decimal(char *nbr, char *base, int *error)
{
	unsigned long int	decimal;
	int					i;
	int					j;
	int					length;

	decimal = 0;
	i = 0;
	length = 0;
	while (base[length])
		length++;
	while (nbr[i])
	{
		j = 0;
		while (nbr[i] != base[j] && base[j])
			j++;
		if ((18446744073709551615U - j) / length < decimal)
			return (*error = 1);
		decimal = (decimal * length) + j;
		i++;
	}
	return (decimal);
}

/*
** -it counts the size needed to be allocated
** -if the given nbr was a negative one it add the place for the '-'
** -then convert the nbr from decimal base to destination base
**  into the string allocated
*/

char
	*decimal_to_base(unsigned long int decimal, char *base, int malloc_size)
{
	int					base_size;
	int					neg;
	char				*result;
	unsigned long int	nb;

	neg = malloc_size;
	base_size = 0;
	while (base[base_size])
		base_size++;
	nb = decimal;
	while (nb /= base_size)
		malloc_size++;
	result = (char *)malloc(sizeof(char) * (malloc_size + 2));
	result[malloc_size + 1] = '\0';
	if (neg)
		result[0] = '-';
	while (malloc_size >= 0)
	{
		result[malloc_size--] = base[decimal % base_size];
		decimal /= base_size;
	}
	return (result);
}

/*
** -main function to convert from one base to another
** -function base_to_decimal has an awfull int *error because it cannot
**  return -1 in case of error, since it's an unsigned, and it cannot
**  return 0 to check the error since it would be confusing with an actual
**  return of 0 if the number to convert is 0
*/

char
	*ft_convertbase(char *nbr, char *base_from, char *base_to)
{
	int					length;
	unsigned long int	decimal;
	int					error;

	error = 0;
	length = 0;
	if (nbr[0] == '-')
	{
		nbr++;
		length = 1;
	}
	if (!is_valid_nbr(nbr, base_from) || !is_valid_base(base_to))
		return (NULL);
	decimal = base_to_decimal(nbr, base_from, &error);
	if (error == 1)
		return (NULL);
	return (decimal_to_base(decimal, base_to, length));
}
