#include <libc.h>

//int		ft_printf(char *string, ...)
//{
//	va_list	ap;
//	int		d;
//	char	c;
//	char	*s;
//
//	va_start(ap, string);
//	while (*string != '\0')
//	{
//		if (*string == 's')
//			s = va_arg(ap, char *);
//		if (*string == 'd')
//			d = va_arg(ap, int);
//		if (*string == 'c')
//			c = va_arg(ap, int);
//		string++;
//	}
//	va_end(ap);
//	return (0);
//}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (s[i])
		i++;
	while (++j < i + 1)
		if (s[j] == c)
			return ((char *)s + j);
	return (NULL);
}

int		main(void)
{
	char	*s = "csd";
	char	*str = "bravo";
	char	c = 'p';
	int		i = 9;

//	ft_printf(s, c, str, i);
	char *test1;
	char *test2;
	test1 = "truc%muche";
	test1 = strdup(test1);
	test2 = ft_strchr(test1,'%');
	if (test2)
		test2[0] = '\0';
	printf("%s", test2);
	test1[6] = 'g';
	if (test2)
		printf(" - %s - %i - %s\n", test2 + 1, test2[0], test1);
	return (0);
}
