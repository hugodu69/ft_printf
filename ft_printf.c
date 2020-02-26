
#include "ft_printf.h"

/*
** FT_FLAG_TRANSFORM :
** 	if i = flag_p(&s)			| -precision is calculated before width,
** 								|  on str, if < length(str), cuts it,
** 		print = ft_precision()	|  on nbr, if > length(nbr), add '0' before,
** 								|  then add '-' if negatif
** 								|  (if precision given with flag '0', it's
** 								|  ignored and cuted from s)
** 	if i = flag_w(s)			| -width is caculated
** 		if flag_-(&s)			| -if flag '-', rm '-' and width from s
** 			print = ft_rpadd()	| -put extra width as ' ' to right,
** 		else if flag_0(&s)		| -if flag '0', rm '0' and width from s
** 			print = ft_lpadd()	| -put extra width as '0' to left
** 		else					| -if just width
** 			print = ft_lpadd()	|  put extra width as ' ' to left
** //	if flag_+(s)			|
** //	else if flag_space(s)	|
** //	if flag_'(s)			|
** //	if flag_#(s)			|
** //		print = ft_altfrm() |
**
** int  flag_p(char **s);
** char *ft_precision(int i, char *print);
** int  flag_w(char *s);
** void flag_-(char **s);
** char *ft_rpadd(int i, char *print);
** char *ft_lpadd(int i, char *print, char c);
*/

char	*ft_flag_transform(char *s, char *print, char *type)
{
	print = ft_precision(s, print, type);
	print = ft_width(s, print);

//	if (flag_+(s))								//
//	else if (flag_space(s))						//
//	if (flag_'(s))								//
//	if (flag_#(s))								//
//		print = ft_alternate_form(print)		//                                           
	return (print);
}

/*
** FT_PRINTF :
**	va_list	ap;
**	int		length;
**	char	*print;				| -contain the arg converted into a string
**	char	*type;				| -contain the specifier type to use
**								|  by va_arg
**	while s = next_word()		| -return the next sequence to be print
**								|  (either a string, or a conversion)
**		type = specifier(s)		| -return the type if it's a conversion, or "%",
**								|  or NULL if it's a string. if it's a
**								|  single '%' it's considered as a string
**								|  if convers0, rmvs length & specifier from s
**		if !type: ft_put_word()	| -print the string if it wasn't a conversion
**		else					|  or if it was a '%%'
**			while strchr(s,*)	| -for each * present, expand it into s in
**				ft_expand_star()|  order it appears
**			print = ft_convert()| -convert the arg with its type,
**								|  then trsfm it into a str and rtrn the str
**			ft_flag_transform()	| -proceed all modification according to flags
**			ft_put_word(print)	| -print the string fully converted
**	return (length)				| -return the length of what was printed
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
			length += ft_put_word(s);
		else
		{
			while (ft_strchr(s, '*'))
				if (!(ft_expand_star(va_arg(ap, int), &s)))
					return (-1);
			if (!(print = ft_convert(ap, type)))
				return (-1);
			if (!(print = ft_flag_transform(s, print, type)))
				return (-1);
			length += ft_put_word(print);
			free(print);
		}
		free(s);
		free(type);
	}
	free(s);
	return (length);
}
