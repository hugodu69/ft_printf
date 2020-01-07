#include <stdarg.h>

int		ft_printf(char *string, ...)
{
	va_list	ap;
	int		d;
	char	c;
	char	*s;

	va_start(ap, string);
	while (*string != '\0')
	{
		if (*string == 's')
			s = va_arg(ap, char *);
		if (*string == 'd')
			d = va_arg(ap, int);
		if (*string == 'c')
			c = va_arg(ap, int);
		string++;
	}
	va_end(ap);
	return (0);
}

int		main(void)
{
	char	*s = "csd";
	char	*str = "bravo";
	char	c = 'p';
	int		i = 9;

	ft_printf(s, c, str, i);
	return (0);
}
