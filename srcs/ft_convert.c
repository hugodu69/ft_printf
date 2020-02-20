
#include "ft_printf.h"

/*
** FT_CONVERT :
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

	s = ft_utoa(i);
	if (c == 's')
		return (strdup((char *)i));
	if (c == 'u')
		return (s);
	if (c == 'x' || c == 'p')
		return (ft_convertbase(s, "0123456789", "0123456789abcdef"));
	if (c == 'X')
		return (ft_convertbase(s, "0123456789", "0123456789ABCDEF"));
	return (NULL);
}

char	*ft_convert(va_list ap, char *type)
{
	char	*s;

	if ((s = ft_strchrset(type, "dic")) && ft_strchr(type, 'l'))
		return (conv_i(s[0], va_arg(ap, long int)));
	if ((s = ft_strchrset(type, "dic")))
		return (conv_i(s[0], va_arg(ap, int)));
	if ((s = ft_strchrset(type, "uxX")) && ft_strchr(type, 'l'))
		return (conv_u(s[0], va_arg(ap, unsigned long int)));
	if ((s = ft_strchrset(type, "uxXp")))
		return (conv_u(s[0], va_arg(ap, unsigned int)));
	if ((s = ft_strchrset(type, "s")))
		return (conv_u(s[0], va_arg(ap, unsigned long int)));
	if (ft_strchrset(type, "efgn"))
		return (NULL);
	return (NULL);
}
