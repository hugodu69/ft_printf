/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 13:58:30 by hulamy            #+#    #+#             */
/*   Updated: 2020/02/24 14:33:47 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** -placed outside of "word_length" for lake of space
** -check if there is a '*' or a number
** -usefull as such for the 'width', and after a check
**  for a '.' for the 'precision' flag
*/

int		width_precision(char *s)
{
	int		i;

	i = 0;
	if (ft_strchr("*", s[i]) != NULL)
		i++;
	while (ft_strchr("0123456789", s[i]) != NULL)
		i++;
	return (i);
}

/*
** -return the length of the next word to print
** -for that it got through the characters expecting
**  in the following order :
**  [%][flags][width][.precision][length][specifier]
**  knowing that 'flags' can repeat themselves
** -a single '%' is treated as a word of length 1
**  (unlike the real printf)
** -it's written :
**   i += width_precision(s + i + 1) + 1;
**  instead of :
**   i++;
**   i += width_precision(s + i);
**  to save a line (3 with the brackets)
*/

int		word_length(char *s)
{
	int		i;

	i = 1;
	if (s[0] == '\0')
		return (0);
	if (s[0] != '%')
	{
		while (s[i] != '%' && s[i] != '\0')
			i++;
		return (i);
	}
	while (ft_strchr("#0- +'", s[i]) != NULL)
		i++;
	i += width_precision(s + i);
	if (ft_strchr(".", s[i]) != NULL)
		i += width_precision(s + i + 1) + 1;
	while (ft_strchr("hl", s[i]) != NULL)
		i++;
	if (ft_strchr("diuxXcspefgn%", s[i]) != NULL)
		i++;
	return (i);
}

/*
** -return the next sequence to be print
**  (either a string, or a conversion)
** -a single '%' is an error in real printf
**  but is treated as a '%' here
*/

char	*next_word(char **string)
{
	char	*s;
	char	*word;
	int		i;

	s = *string;
	if (*s == '\0')
		return (NULL);
	if ((i = word_length(s)) < 0)
		return (NULL);
	word = (char *)malloc(sizeof(char) * (i + 1));
	word[i] = '\0';
	ft_memmove(word, s, i);
	*string += i;
	return (word);
}
