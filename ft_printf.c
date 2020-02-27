/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:01:26 by hulamy            #+#    #+#             */
/*   Updated: 2020/02/27 12:01:30 by hulamy           ###   ########.fr       */
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

/*
** print the string
** because of lake of space, it also free 'type'
*/

int		ft_put_word(char *s, char *type)
{
	int		i;

	free(type);
	i = ft_strlen(s);
	ft_putstr(s);
	free(s);
	return (i);
}

/*
** print the string
** because of lake of space, it also free 'type'
*/

int		length_n_free(int length, char *s)
{
	free(s);
	return (length);
}

/*
** -printf receive a string to print with a variadic number of arguments
** -it will go in a loop through each 'words'
** -a word is either a string containing no '%' or a conversion starting by '%'
** -if it's a string it's printed right away
** -if it's a conversion it will go through some actions :
** -1 expand all the stars from width and .precision
**    they always expand into int type
**    it's done first because those are the first next args on the va_list
** -2 expand the specifier according to its type and its length
**    and put in a string 'print'
** -3 transform 'print' according to the flags
*/

int		ft_printf(char *string, ...)
{
	char	*s;
	char	*print;
	char	*type;
	int		length;
	va_list	ap;

	length = 0;
	va_start(ap, string);
	while ((s = next_word(&string)) != NULL)
	{
		if ((type = specifier(s)) == NULL)
			length += ft_put_word(s, type);
		else
		{
			while (ft_strchr(s, '*'))
				if (!(ft_expand_star(va_arg(ap, int), &s)))
					return (-1);
			if (!(print = ft_convert(ap, type)))
				return (-1);
			if (!(print = ft_flag_transform(s, print, type)))
				return (-1);
			length += ft_put_word(print, type);
		}
	}
	return (length_n_free(length, s));
}
