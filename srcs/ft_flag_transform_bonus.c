
#include "ft_printf.h"

char	*ft_plus(char *s, char *print, char *type)
{
	if (!ft_strchrset(type, "di"))
		return (print);
	if (ft_strchr(s, '+') && !ft_strchr(print, '-'))
		print = ft_concat_free(ft_strdup("+"), print);
	return (print);
}

char	*ft_sharp(char *s, char *print, char *type)
{
	if (ft_strchr(s, '#'))
	{
		if (ft_strchr(type, 'x'))
			print = ft_concat_free(ft_strdup("0x"), print);
		else
			print = ft_concat_free(ft_strdup("0X"), print);
	}
	return (print);
}

char	*ft_sharp_again(char *s, char *print, char *type)
{
	char	*tmp;

	if (!ft_strchr(s, '#'))
		return (print);
	if (print[0] == '0' && print[1] == '0' && ft_strchrset(type, "xX"))
	{
		tmp = ft_strchrset("xX", print);
		print[1] = tmp[0];
		tmp[0] = '0';
	}
	return (print);
}

char	*ft_space(char *s, char *print, char *type, int *size)
{
	int i = 0;

	if (print[0] == ' ' || !ft_strchr(s, ' ') || !ft_strchrset(type, "diuxX"))
		return (print);
	while (print[i] == ' ')
		i++;
	if (print[i] == '-' || print[i] == '+')
		return (print);
	if (ft_strchr(s, '.') || (i == 0 && print[i] != '0'))
	{
		print = ft_concat_free(ft_strdup(" "), print);
		*size += 1;
	}
	else
		print[i] = ' ';
	if (ft_strchr(s, '-') && print[*size - 1] == ' ')
	{
		print[*size] = '\0';
		*size -= 1;
	}
	return (print);
}
