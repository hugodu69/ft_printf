/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aside.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 16:23:01 by hulamy            #+#    #+#             */
/*   Updated: 2020/02/24 14:34:16 by hulamy           ###   ########.fr       */
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
	char	*strnbr;
	int		i;
	int		j;

	strnbr = ft_itoa(nbr);
	i = ft_strlen(strnbr) + ft_strlen(*string) - 1;
	if (!(s = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	s[i] = '\0';
	i = 0;
	j = 0;
	while ((*string)[i] != '\0')
	{
		s[j] = (*string)[i];
		if (s[j] == '*')
			while (*strnbr != '\0')
				s[j++] = *(strnbr++);
		else
			j++;
		i++;
	}
	free(*string);
	*string = s;
	return (1);
}
