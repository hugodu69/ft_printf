#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

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
	c = 'c';
	i = 6;
	ft_printf(s, str, c, i);
	printf("\n");

		printf("-----------------------------------------------\n");
		printf("-                   BASICS                    -\n");
		printf("-                                             -\n");
		printf("- %%[flag][width][.precision][length]specifier -\n");
		printf("-                                             -\n");
		printf("- conversions : cspdiuxX%%                     -\n");
		printf("-       flags : -0.*                          -\n");
		printf("- taille de champ minimale                    -\n");
		printf("-                                             -\n");
		printf("- char  *str = \"bravo\";                       -\n");
		printf("- char  c = 'c';                              -\n");
		printf("- int   i = 6;                                -\n");
		printf("-----------------------------------------------\n");
		printf("-----------------------------------------------\n");
		printf("- conversions : cspdiuxX%%                     -\n");
		printf("-----------------------------------------------\n\n");

	//	printf("(\"no newline\") ft : ");	ft_printf("no newline"); printf("-->ligne suivante\n");
		printf("(\"no newline\")    : ");	   printf("no newline"); printf("-->ligne suivante\n"); printf("\n");

	//	printf("(\"newline\\n\")  ft : ");	ft_printf("newline\n"); printf("-->ligne suivante\n");
		printf("(\"newline\\n\")     : ");	   printf("newline\n"); printf("-->ligne suivante\n"); printf("\n");

	//	printf("(\"%%%%\")         ft : ");	 ft_printf("%%\n");
		printf("(\"%%%%\")            : ");	    printf("%%\n"); printf("\n");

	//	printf("(\"\\\"\")         ft : ");	ft_printf("\"\n");
		printf("(\"\\\"\")            : ");	   printf("\"\n"); printf("\n");

	//	printf("(\"%%c\",'c')     ft : ");	ft_printf("%c\n", 'c');
		printf("(\"%%c\",'c')        : ");	   printf("%c\n", 'c'); printf("\n");

	//	printf("(\"%%s\",\"str\")   ft : ");	ft_printf("%s\n", "str");
		printf("(\"%%s\",\"str\")      : ");	   printf("%s\n", "str"); printf("\n");

	//	printf("(\"%%s\",str)     ft : ");	ft_printf("%s\n", str);
		printf("(\"%%s\",str)        : ");	   printf("%s\n", str); printf("\n");

	//	printf("(\"%%p\",str)     ft : ");	ft_printf("%p\n", str);
		printf("(\"%%p\",str)        : ");	   printf("%p\n", str); printf("\n");

	//	printf("(\"%%d\",456)     ft : ");	ft_printf("%d\n", 456);
		printf("(\"%%d\",456)        : ");	   printf("%d\n", 456); printf("\n");

	//	printf("(\"%%i\",846)     ft : ");	ft_printf("%i\n", 846);
		printf("(\"%%i\",846)        : ");	   printf("%i\n", 846); printf("\n");

	//	printf("(\"%%u\",87)      ft : ");	ft_printf("%u\n", 87);
		printf("(\"%%u\",87)         : ");	   printf("%u\n", 87); printf("\n");

	//	printf("(\"%%u\",-87)     ft : ");	ft_printf("%u\n", -87);
		printf("(\"%%u\",-87)        : ");	   printf("%u\n", -87); printf("\n");

	//	printf("(\"%%x\",124)     ft : ");	ft_printf("%x\n", 124);
		printf("(\"%%x\",124)        : ");	   printf("%x\n", 124); printf("\n");

	//	printf("(\"%%X\",124)     ft : ");	ft_printf("%X\n", 124);
		printf("(\"%%X\",124)        : ");	   printf("%X\n", 124); printf("\n");

		printf("-----------------------------------------------\n");
		printf("- flags : -0.*                                -\n");
		printf("- taille de champ minimale                    -\n");
		printf("-----------------------------------------------\n\n");

		printf("- taille de champ minimale --------------------\n\n");

	//	printf("(\"%%3s\",\"a\")     ft : ");	ft_printf("'%3s'\n", "a");
		printf("(\"%%3s\",\"a\")        : ");	   printf("'%3s'\n", "a"); printf("\n");

	//	printf("(\"%%3s\",\"abcd\")  ft : ");	ft_printf("'%3s'\n", "abcd");
		printf("(\"%%3s\",\"abcd\")     : ");	   printf("'%3s'\n", "abcd"); printf("\n");

	//	printf("(\"%%3i\",12)      ft : ");	ft_printf("'%3i'\n", 12);
		printf("(\"%%3i\",12)         : ");	   printf("'%3i'\n", 12); printf("\n");

	//	printf("(\"%%2i\",12)      ft : ");	ft_printf("'%2i'\n", 12);
		printf("(\"%%2i\",12)         : ");	   printf("'%2i'\n", 12); printf("\n");

	//	printf("(\"%%1i\",12)      ft : ");	ft_printf("'%1i'\n", 12);
		printf("(\"%%1i\",12)         : ");	   printf("'%1i'\n", 12); printf("\n");

		printf("- flag - --------------------------------------\n\n");

	//	printf("(\"%%-3s\",\"a\")    ft : ");	ft_printf("'%-3s'\n", "a");
		printf("(\"%%-3s\",\"a\")       : ");	   printf("'%-3s'\n", "a"); printf("\n");

	//	printf("(\"%%-9s\",\"a\")    ft : ");	ft_printf("'%-9s'\n", "a");
		printf("(\"%%-9s\",\"a\")       : ");	   printf("'%-9s'\n", "a"); printf("\n");

	//	printf("(\"%%-1s\",\"ab\")   ft : ");	ft_printf("'%-1s'\n", "ab");
		printf("(\"%%-1s\",\"ab\")      : ");	   printf("'%-1s'\n", "ab"); printf("\n");

	//	printf("(\"%%-2s\",\"ab\")   ft : ");	ft_printf("'%-2s'\n", "ab");
		printf("(\"%%-2s\",\"ab\")      : ");	   printf("'%-2s'\n", "ab"); printf("\n");

	//	printf("(\"%%-3s\",\"ab\")   ft : ");	ft_printf("'%-3s'\n", "ab");
		printf("(\"%%-3s\",\"ab\")      : ");	   printf("'%-3s'\n", "ab"); printf("\n");

	//	printf("(\"%%-3i\",3)      ft : ");	ft_printf("'%-3i'\n", 3);
		printf("(\"%%-3i\",3)         : ");	   printf("'%-3i'\n", 3); printf("\n");

	//	printf("(\"%%-3i\",123456) ft : ");	ft_printf("'%-3i'\n", 123456);
		printf("(\"%%-3i\",123456)    : ");	   printf("'%-3i'\n", 123456); printf("\n");

		printf("- flag 0 --------------------------------------\n\n");

	//	printf("(\"%%03i\",1)      ft : ");	ft_printf("'%03i'\n", 1);
		printf("(\"%%03i\",1)         : ");	   printf("'%03i'\n", 1); printf("\n");

		printf("- flag * --------------------------------------\n\n");

	//	printf("(\"%%*i\",3,1)     ft : ");	ft_printf("'%*i'\n", 3, 1);
		printf("(\"%%*i\",3,1)        : ");	   printf("'%*i'\n", 3, 1); printf("\n");

	//	printf("(\"%%-*i\",3,1)    ft : ");	ft_printf("'%-*i'\n", 3, 1);
		printf("(\"%%-*i\",3,1)       : ");	   printf("'%-*i'\n", 3, 1); printf("\n");

		printf("- flag * --------------------------------------\n\n");

		printf("(\"%%.5i\",12)        : ");	   printf("'%.5i'\n", 12); printf("\n");

		printf("-----------------------------------------------\n");
		printf("- errors                                      -\n");
		printf("-----------------------------------------------\n\n");

	//	printf("(\"%%i\",3,2)        ft : ");	ft_printf("'%i'", 3, 2);
	//	printf("(\"%%i\",3,2)           : ");	   printf("'%i'", 3, 2); printf(" [ERROR]\n\n");

	//	printf("(\"%%i-%%i\",3)        ft : ");	ft_printf("'%i-%i'", 3);
	//	printf("(\"%%i-%%i\",3)           : ");	   printf("'%i-%i'", 3); printf(" [ERROR]\n\n");

	//	printf("(\"%%-03i\",1)     ft : ");	ft_printf("'%-03i'\n", 1);
	//	printf("(\"%%-03i\",1)        : ");	   printf("'%-03i'\n", 1); printf("\n");

	//	printf("(\"%%010s\",str)   ft : ");	ft_printf("'%010s'\n", str);
	//	printf("(\"%%010s\",str)      : ");	   printf("'%010s'\n", str); printf("\n");

	//	printf("(\"%%-010s\",str)  ft : ");	ft_printf("'%-010s'\n", str);
	//	printf("(\"%%-010s\",str)     : ");	   printf("'%-010s'\n", str); printf("\n");


		printf("-----------------------------------------------\n");
		printf("-                    BONUS                    -\n");
		printf("- conversions : nfge                          -\n");
		printf("-       flags : l ll h hh # ' +               -\n");
		printf("-----------------------------------------------\n\n");

	//	printf("-----------------------------------------------\n");
	//	printf("-                     ADD                     -\n");
	//	printf("-       flags : $                             -\n");
	//	printf("-----------------------------------------------\n\n");

	//	printf("(\"%%1$*2$i\",3,2) ft : ");	ft_printf("'%1$*2$i'\n", 3, 2);
	//	printf("(\"%%1$*2$i\",3,2)    : ");	   printf("'%1$*2$i'\n", 3, 2); printf("\n");

	//	printf("(\"%%2$*1$i\",3,2) ft : ");	ft_printf("'%2$*1$i'\n", 3, 2);
	//	printf("(\"%%2$*1$i\",3,2)    : ");	   printf("'%2$*1$i'\n", 3, 2); printf("\n");

	return (0);
}

	//	usage :
	//	%[flags][width][.precision][length]specifier
	//
	//	[specifiers]
	//	c		character
	//	s		string of characters
	//	p		pointer adress
	//	d		(or i) signed decimal integer
	//	i		(or d) signed decimal integer
	//	u		unsigned decimal integer
	//	x		unsigned hexadecimal integer
	//	X		unsigned hexadecimal integer (capital letters)
	//(	n		nothing printed
	//(	f		decimal floating point
	//(	g		uses the shorter of %e or %f
	//(	e		scientific notation (mantissa/exponent) using e
	//((E		scientific notation (mantissa/exponent) using E
	//((G		uses the shorter of %E or %f
	//((o		signed octal
	//
	//	[flags]
	//	-		left-justify within the given field width
	//	0		left-pads the number with zeroes (0) instead of spaces, where
	//			padding is specified (see width sub-specifier)
	//(	+		forces to precede the result with a plus or minus sign even for
	//			positive numbers)
	//(	(space)	if no sign is going to be written, a blank space is inserted
	//			before the value)
	//(	#		used with o, x or X specifiers the value is preceded with 0, 0x
	//			or 0X respectively for values different than zero. Used with e,
	//			E and f, it forces the written output to contain a decimal point
	//			even if no digits would follow. By default, if no digits follow,
	//			no decimal point is written. Used with g or G the reult is the
	//			same as with e or E but trailing zeros are not removed)
	//
	//	[width]
	//	(nbr)	minimum number of characters to be printed. if the value to be
	//			printed is shorter than this number, the result is padded with
	//			blank spaces. The value is not truncated even if the result is
	//			larger
	//	*		the width is not specified in the format string, but as an
	//			additional integer value argument preceding the argument that
	//			has to be formatted
	//
	//	[.precision]
	//	.nbr	fot integer specifiers (d,i,o,x,X) - precision specifies the
	//			minimum number of digits to be written. If the value to be
	//			written is shorter than this number, the result is padded with
	//			leading zeros. The value is not truncated even if the result is
	//			longer. A precision of 0 means that no character is written for
	//			the value 0. For e, E and f specifiers − this is the number of
	//			digits to be printed after the decimal point. For g and G
	//			specifiers − This is the maximum number of significant digits
	//			to be printed. For s − this is the maximum number of characters
	//			to be printed. By default all characters are printed until the
	//			ending null character is encountered. For c type − it has no
	//			effect. When no precision is specified, the default is 1. If the
	//			period is specified without an explicit value for precision, 0
	//			is assumed
	//	.*		the precision is not specified in the format string, but as an
	//			additional integer value argument preceding the argument that
	//			has to be formated
	//
