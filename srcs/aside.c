/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aside.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:23:01 by hulamy            #+#    #+#             */
/*   Updated: 2020/02/26 17:43:21 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** SPECIFIER :
**  receive a word as a string, check if it start by '%', and return the
**  specifier (diuxXspefgn) and the length (h hh l ll)
** -if s is a string, or is a single '%'
**  return NULL (to print is as a string)
** -if s is a double '%%', remove one '%', and
**  return NULL (to print is as a string)
** -then s is a conversion, go to the length and specifier
** -copy them in 'string'
** -and remove them from s
** -return the length and specifier in a string
*/

char	*specifier(char *s)
{
	char	*string;
	int		i;

	if (s[0] != '%' || s[1] == '\0')
		return (NULL);
	if (s[1] == '%')
	{
		s[1] = '\0';
		return (NULL);
	}
	i = 1;
	while (ft_strchr("#0- +'0123456789.*", s[i]) != NULL)
		i++;
	string = ft_strdup(s + i);
	while (s[i] != '\0')
	{
		s[i] = '\0';
		i++;
	}
	return (string);
}

/*
** print the string
*/

int		ft_put_word(char *s)
{
	int		i;

	i = ft_strlen(s);
	ft_putstr(s);
	return (i);
}

/*
** -receive 'i' the number in which '*' will expand
** -turn it into a string
** -calculate the total lentgh of the string '%...' for nbr replacing '*'
** -allocate a new string with this length
** -copy the original str with first '*' expanded into it's corresponding  nbr
*/

int		ft_expand_star(int nbr, char **string)
{
	char	*s;
	char	*n;
	int		i;
	int		j;
	int		k;

	n = ft_itoa(nbr);
	if (!(s = ft_memalloc(sizeof(char) * (ft_strlen(n) + ft_strlen(*string)))))
		return (0);
	i = -1;
	j = 0;
	k = 0;
	while ((*string)[++i] != '\0')
	{
		s[j] = (*string)[i];
		if (s[j] == '*')
			while (n[k] != '\0')
				s[j++] = n[k++];
		else
			j++;
	}
	free(n);
	free(*string);
	*string = s;
	return (1);
}
