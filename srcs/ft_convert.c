/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hulamy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 22:30:05 by hulamy            #+#    #+#             */
/*   Updated: 2020/03/12 22:30:20 by hulamy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** -convert the next argument into a string according to the following
**  correspondances for diuxXcspefgn :
**  [char]				[hhd, hhi, c]			[int]			[d i c]
**  [short]				[hd, hi]				[int]
**  [int]				[d, i]					[int]
**  [long]				[ld, li]				[long]			[ld li]
**  [long long]			[lld, lli]				[long]
**  [unsigned char]		[hhu, hhx, hhX]			[unsigned int]	[u x X p s]
**  [unsigned short]	[hu, hx, hX]			[unsigned int]
**  [unsigned int]		[u, x, X, p]			[unsigned int]
**  [unsigned long]		[lu, lx, lX]			[unsigned long]	[lu lx lX]
**  [unsigned long long][llu, llx, llX]			[unsigned long]
**  [char *]			[s, hhn]
**  [double]			[e, le, f, lf, g, lg]
**  [wint_t]			[lc]
**  [wchar_t]			[ls]
**  [short *]			[hn]
**  [int *]				[n]
**  [long *]			[ln]
**  [long long *]		[lln]
** -'h' and 'hh', are traited just like regular size because of
**  default promotion, that promote smaller type than int into int
*/

char	*conv_i(char c, long int i)
{
	char	*s;

	if (c == 'c')
	{
		s = ft_strdup("0");
		s[0] = i;
		return (s);
	}
	if (c == 'd' || c == 'i')
		return (ft_itoa(i));
	return (NULL);
}

char	*conv_u(char c, unsigned long int i)
{
	char	*s;

	if (c == 's')
		return (strdup((char *)i));
	s = ft_utoa(i);
	if (c == 'u')
		return (s);
	if (c == 'x' || c == 'p')
		return (ft_convertbase_free(s, "0123456789", "0123456789abcdef"));
	if (c == 'X')
		return (ft_convertbase_free(s, "0123456789", "0123456789ABCDEF"));
	return (NULL);
}

/*
** -first a loop to expand all the stars from width and .precision
**  they always expand into int type
**  it's done first because those are the first next args on the va_list
** -for each kind of specifier there is finally four kinds of conversion :
**  int / long int / unsigned int / unsingned long int
** -the conversion 'uxX' associated with 'l' are converted with lu, but
**  also are 'p' and 's', without an 'l' flag, that's why there is this little
**  trick on line the line for unsigned int :
** -'uxXps' && 'lps' will make it looks for 'uxX' and for 'l'
**  (because it will never find a 'p' or a 's' if there are 'uxX' already)
**  or for 'p' and again for 'p', or 's' twice similarly
*/

char	*ft_convert(va_list ap, char *type, char **s)
{
	char	*tmp;

	while (ft_strchr(*s, '*'))
		if (!(ft_expand_star(va_arg(ap, int), s)))
			return (NULL);
	if ((tmp = ft_strchrset(type, "dic")) && ft_strchr(type, 'l'))
		return (conv_i(tmp[0], va_arg(ap, long int)));
	if ((tmp = ft_strchrset(type, "dic")))
		return (conv_i(tmp[0], va_arg(ap, int)));
	if ((tmp = ft_strchrset(type, "uxXps")) && ft_strchrset(type, "lps"))
		return (conv_u(tmp[0], va_arg(ap, unsigned long int)));
	if ((tmp = ft_strchrset(type, "uxX")))
		return (conv_u(tmp[0], va_arg(ap, unsigned int)));
	if (ft_strchr(type, '%'))
		return (ft_strdup("%"));
	if (ft_strchrset(type, "efgn"))
		return (NULL);
	return (NULL);
}
