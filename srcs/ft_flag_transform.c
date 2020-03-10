
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
** -0 if .precision is 0 && print is "0": print nothing
** -1 if type is s: if length(s) > precision, removes end of 'print' to print
**    only x chars, with x = precision
** -2 if type is "diouxX": call fonction 'precision_int' that return :
**    if length(s) < precision, add x '0' bfr nbr, but after '-' if negative
** -3 if type is "aAeEfF": not covered
** -4 if type is "gG": not covered
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
		while (*s && ft_strchr("#- +'0", *(++s)))
			if (*s == '0')
				*s = '.';
		i = 0;
		if (precision == 0 && !ft_strcmp(print, "0"))
			print[0] = '\0';
		else if (ft_strchr(type, 's'))
		{
			while (i < precision && print[i])
				i++;
			if (print[i])
				print[i] = '\0';
		}
		else if (ft_strchrset(type, "diouxX"))
			print = precision_int(print, precision);
	}
	return (print);
}

/*
** -if flag '-' is present, put extra width as ' ' to right of 'print'
** -if flag '0' is present, put extra width as '0' to left of 'print'
** -else, put extra width as ' ' to left of 'print'
*/

char	*width_flags(char *print, char *s, int width, int zero)
{
	char	*tmp;
	char	*minus;
	char	c;
	int		len;

	len = ft_strlen(print) + zero;
	if (!(tmp = ft_strnew(width)))
		return (NULL);
	if (ft_strchr(s, '-'))
	{
		ft_memmove(tmp, print, len);
		ft_memset(tmp + len, ' ', width - len);
	}
	else
	{
		ft_memset(tmp, (ft_strchr(s, '0')) ? '0' : ' ', width - len);
		ft_memmove(ft_strchr(tmp, '\0') + zero, print, ft_strlen(print));
		if (ft_strchr(s, '0') && (minus = ft_strchrset("+-", tmp)))
		{
			tmp[0] = (minus[0] == '+') ? '+' : '-';
			minus[0] = '0';
		}
	}
	free(print);
	return (tmp);
}

/*
** -if there is a minimal width field, calculate it and add it to print
**  according to the flags '-' and '0' if present
** -in details :
**  0 if print[0] value 0, as it happens for type c with (char)0, save it for
**    later in 'zero'
**  1 loop through s, the string starting by '%' and ending by a converter,
**    until it has passed all the flags that are not a potentiel width field
**  2 then if it's the end of s, there is no width and print isn't changed,
**    otherwise the int 'size' take the value returned by atoi
**    in case print isn't changed, 'size' is the length of 'print'
**  3 then if the size of the width shield is bigger than the size of print
**    (plus zero in case print is a (char)0), call 'width_flags' that will
**    create a new char* to contain the string to print after transformation
**  4 otherwise 'size' is the length of print + zero
*/

char	*ft_width(char *s, char *print, int *size, char *type)
{
	char	*tmp;
	int		zero;

	tmp = s;
	zero = 0;
	if (print[0] == '\0' && ft_strchr(type, 'c'))
		zero = 1;
	while (*tmp != '\0' && ft_strchr("%#- +'0.", *tmp))
		tmp++;
	if (*tmp == '\0')
	{
		*size = ft_strlen(print) + zero;
		return (print);
	}
	*size = ft_atoi(tmp);
	tmp[0] = '\0';
	if (*size > ft_strlen(print) + zero)
		print = width_flags(print, s, *size, zero);
	else
		*size = ft_strlen(print) + zero;
	return (print);
}

/*
** -go through all the transformation flags needs
** -first the precision
** -then if type is int and nbr is positive, add a + to the left, it's flag '+'
** -third the flag "#"
** -fourth, the width
** -then p
** -the case of 'p' is treated without any subtelness because i don't care
*/

char	*ft_flag_transform(char *s, char *print, char *type, int *size)
{
	print = ft_precision(s, print, type);
	print = ft_plus(s, print, type);
	print = ft_sharp(s, print, type);
	print = ft_width(s, print, size, type);
	print = ft_sharp_again(s, print, type);
	if (ft_strchr(type, 'p'))
	{
		print = ft_concat_free(ft_strdup("0x"), print);
		*size += 2;
	}
	return (print);
}
