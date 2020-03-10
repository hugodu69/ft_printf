
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

