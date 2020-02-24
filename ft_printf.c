
#include "ft_printf.h"

/*
** -function that modify the string 'print' according to the precision flag :
**  if length(s) < precision, add x '0' bfr nbr, but after '-' if negative
*/

char	*precision_int(char *print, int precision)
{
	int		i;
	char	*tmp;

	i = ft_strlen(print);
	if (print[0] == '-')
		precision++;
	if (precision > i)
	{
		if (!(tmp = (char *)malloc(sizeof(char) * (precision + 1))))
			return (NULL);
		tmp[precision] = '\0';
		if (print[0] == '-')
			tmp[0] = '-';
		while (i)
			tmp[--precision] = print[--i];
		if (print[0] == '-')
			precision++;
		while (precision)
			tmp[--precision] = '0';
		if (print[0] == '-')
			tmp[0] = '-';
		free(print);
		print = tmp;
	}
	return (print);
}

/*
** -it first verify if there is a precision point, and if so, it execute a
**  serie of action listed below, otherwise return print as it is
**  ACTIONS :
** -look for a '.'
** -if followed by numbers, extract an int version of those numbers
** -if the '.' is alone, gives value '0' to the int
** -then removes the '.' and the numbers from the %string
** -if flag '0' is present in %string, removes it (actually turn each occurence
**  in a '.')
** -and transform 'print' according to the precision :
** -1 if type is s: if length(s) > precision, removes end of 'print' to print
**    only x chars, with x = precision
** -2 if type is "diouxX": call fonction 'precision_int' that return :
**    if length(s) < precision, add x '0' bfr nbr, but after '-' if negative
** -3 if type is "aAeEfF": not covered
** -4 si type is "gG": not covered
** -5 else: error
*/

char	*ft_precision(char *s, char *print, char *type)
{
	char	*tmp;
	int		precision;
	int		i;

	if ((tmp = ft_strchr(s, '.')))
	{
		precision = ft_atoi(tmp + 1);
		*tmp = '\0';
		while (ft_strchr("#- +'0", *(++s)))
			if (*s == '0')
				*s = '.';
		i = 0;
		if (ft_strchr(type, 's'))
		{
			while (i < precision && print[i])
				i++;
			if (print[i])
				print[i] = '\0';
		}
		if (ft_strchrset(type, "diouxX"))
			print = precision_int(print, precision);
	}
	return (print);
}

/*
**
** 	if i = flag_w(s)			| -width is caculated
** 		if flag_-(&s)			| -if flag '-', rm '-' and width from s
** 			print = ft_rpadd()	| -put extra width as ' ' to right,
** 		else if flag_0(&s)		| -if flag '0', rm '0' and width from s
** 			print = ft_lpadd()	| -put extra width as '0' to left
** 		else					| -if just width
** 			print = ft_lpadd()	|  put extra width as ' ' to left
*/

char	*ft_width(char *s, char *print)
{
	char	*tmp;
	int		i;																		ft_putstr("[");ft_putstr(s);ft_putstr("|");

	tmp = s;
	while (*tmp != '\0' && ft_strchr("%#- +'0.", *tmp))
		tmp++;
	i = ft_atoi(tmp);																ft_putnbr(i);ft_putstr("|");
	tmp[0] = '\0';																	ft_putstr(s);ft_putstr("]");
	if (i > ft_strlen(print))
	{
		if (!(tmp = (char *)malloc(sizeof(char) * (i + 1))))
			return (NULL);
		tmp[i] = '\0';
		if (ft_strchr(s, '-'))
		{
			while (*print)
			{
				*tmp = *print;
				tmp++;
				print++;
				i--;
			}
			while (i)
			{
				*tmp = ' ';
				tmp++;
				i--;
			}
		}
		else if (ft_strchr(s, '0'))
		{
			i -= ft_strlen(print);
			while (i)
			{
				*tmp = '0';
				tmp++;
				i--;
			}
			while (*print)
			{
				*tmp = *print;
				tmp++;
				print++;
			}
		}
		else
		{
			i -= ft_strlen(print);
			while (i)
			{
				*tmp = ' ';
				tmp++;
				i--;
			}
			while (*print)
			{
				*tmp = *print;
				tmp++;
				print++;
			}
		}
//		ft_putstr(tmp);
		print = tmp;
	}
	return (print);
}

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
{																					ft_putstr("[");ft_putstr(s);ft_putstr("]");
	print = ft_precision(s, print, type);
	print = ft_width(s, print);
//	if ((i = flag_w(s)))
//	{
//		if (flag_-(&s))
//			print = ft_rpadd(i, print);
//		else if (flag_0(&s))
//			print = ft_lpadd(i, print, '0');
//		else
//			print = ft_lpadd(i, print, ' ');
//	}

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
		}
	}
	return (length);
}
