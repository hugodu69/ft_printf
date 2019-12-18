#include <libc.h>

int		ft_printf(char *fmt, ...)
{
	va_list	ap;
	int		d;
	char	c, *s;

	va_start(ap, fmt);
	while (*fmt)
		switch(*fmt++) {
			case 's':                       /* string */
				s = va_arg(ap, char *);
				printf("string %s\n", s);
				break;
			case 'd':                       /* int */
				d = va_arg(ap, int);
				printf("int %d\n", d);
				break;
			case 'c':                       /* char */
				/* Note: char is promoted to int. */
				c = va_arg(ap, int);
				printf("char %c\n", c);
				break;
		}
	va_end(ap);
	return (0);
}

int		main(void)
{
	char	*s;
	char	*str;
	char	c;
	int		i;

	s = "scd";
	str = "bravo";
	c = 'y';
	i = 6;
	ft_printf(s, str, c, i);
	return (0);
}
