
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
		while (ft_strchr("#- +'0", *(++s)))
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

char	*width_flags(char *print, char *tmp, char *s, int width, int zero)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ft_strchr(s, '-'))
	{
		if (print[j] == '\0')
			tmp[i++] = '\0';
		while (print[j] != '\0')
			tmp[i++] = print[j++];
		while (i < width)
			tmp[i++] = ' ';
	}
	else
	{
		c = (ft_strchr(s, '0')) ? '0' : ' ';
		while (i < (width - ft_strlen(print) - zero))
			tmp[i++] = c;
		if (print[j] == '\0')
			tmp[i++] = '\0';
		while (print[j] != '\0')
			tmp[i++] = print[j++];
	}
	free(print);
	return (tmp);
}

/*
** -if there is a minimal width field, calculate it and add it to print
**  according to the flags '-' and '0' if present
** -in details :
**  1 loop through s, the string starting by '%' and ending by a converter,
**    until it has passed all the flags that are not a potentiel width field
**  2 then if it's the end of s, there is no width and print isn't changed,
**    otherwise the int 'width' take the value returned by atoi
**  3 if print[0] value 0, as it happens for type c with (char)0,
*/

char	*ft_width(char *s, char *print, int *size)
{
	char	*tmp;
	int		zero;

	tmp = s;
	zero = 0;
	while (*tmp != '\0' && ft_strchr("%#- +'0.", *tmp))
		tmp++;
	if (*tmp == '\0')
	{
		*size = ft_strlen(print);
		return (print);
	}
	*size = ft_atoi(tmp);
	tmp[0] = '\0';
	if (print[0] == '\0')
		zero = 1;
	if (*size > ft_strlen(print) + zero)
	{
		if (!(tmp = (char *)malloc(sizeof(char) * (*size + 1))))
			return (NULL);
		tmp[*size] = '\0';
		print = width_flags(print, tmp, s, *size, zero);
	}
	else
		*size = ft_strlen(print);
	return (print);
}

/*
** -go through all the transformation flags needs
** -the case of 'p' is treated without any subtelness because i don't care
*/

char	*ft_flag_transform(char *s, char *print, char *type, int *size)
{
	print = ft_precision(s, print, type);
	print = ft_width(s, print, size);
	if (ft_strchr(type, 'p'))
	{
		print = ft_concat_free(ft_strdup("0x"), print);
		*size += 2;
	}
	return (print);
}
