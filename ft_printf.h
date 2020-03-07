/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 12:07:47 by hulamy            #+#    #+#             */
/*   Updated: 2020/02/27 12:08:40 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft/includes/libft.h"

# include <stdio.h>

/*
** ft_printf.c
*/

char	*specifier(char *s);
int		ft_expand_star(int nbr, char **string);
int		ft_put_word(char *s, char *type, int size);
char	*convert_with_flags(char *s, va_list ap, char *type, int *size);
int		ft_printf(char *string, ...);

/*
** ft_next_word.c
*/

int		width_precision(char *s);
int		word_length(char *s);
char	*next_word(char **s);

/*
** ft_convert.c
*/

char	*conv_i(char c, long int i);
char	*conv_u(char c, unsigned long int i);
char	*ft_convert(va_list ap, char *type, char **s);

/*
** ft_flag_transform.c
*/

char	*precision_int(char *print, int precision);
char	*ft_precision(char *s, char *print, char *type);
char	*width_flags(char *print, char *s, int width, int zero);
char	*ft_width(char *s, char *print, int *size);
char	*ft_flag_transform(char *s, char *print, char *type, int *size);

#endif
