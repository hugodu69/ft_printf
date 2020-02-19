
#include "ft_printf.h"

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
			print = ft_convert(ap, type);
		//	print = ft_flag_transform(s, print);
			length += ft_put_word(print);
		}
	}
	return (length);
}

/*
** FT_FLAG_TRANSFORM :
** 	if i = flag_p(&s)			| -precision is calculated before width,
** 								|  on str, if < length(str), cuts it,
** 		print = ft_precision()	|  on nbr, if > length(nbr), add '0' before,
** 								|  then add '-' if negatif
** 								|  (if precision given with flags '-' or '0'
** 								|  they're ignored and cuted from s)
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

/*
char	*ft_flag_transform(char *s, char *print)
{
	if ((i = flag_p(&s)))
		print = ft_precision(i, print);
	if ((i = flag_w(s)))
	{
		if (flag_-(&s))
			print = ft_rpadd(i, print);
		else if (flag_0(&s))
			print = ft_lpadd(i, print, '0');
		else
			print = ft_lpadd(i, print, ' ');
	}
//	if (flag_+(s))								//
//	else if (flag_space(s))						//
//	if (flag_'(s))								//
//	if (flag_#(s))								//
//		print = ft_alternate_form(print)		//                                           
}
*/

int		ft_printf_test(char *string, ...)
{
	va_list	ap;

	va_start(ap, string);
	printf("%s", string);
	while (*string != '\0')
	{
		printf(" : ");
		if (*string == 'd')
			printf("%d", (int)va_arg(ap, long int));
		if (*string == 'i')
			printf("%i", (int)va_arg(ap, long int));
		if (*string == 'u')
			printf("%u", (unsigned int)va_arg(ap, int));
		if (*string == 'x')
			printf("%x", (unsigned int)va_arg(ap, long int));
		if (*string == 'X')
			printf("%X", (unsigned int)va_arg(ap, long int));
		if (*string == 'c')
			printf("%c", (char)va_arg(ap, long int));			// var_arg promote char into int
		if (*string == 's')
			printf("%s", (char *)va_arg(ap, long int));
		if (*string == 'e')
			printf("%e", va_arg(ap, double));					// va_arg promote float into double
		if (*string == 'f')
			printf("%f", va_arg(ap, double));					// va_arg promote float into double
		if (*string == 'g')
			printf("%g", va_arg(ap, double));					// va_arg promote float into double
		if (*string == 'I')
			printf("%li", (long int)va_arg(ap, long int));
		if (*string == 'U')
			printf("%lu", (unsigned long int)va_arg(ap, long int));
		string++;
	}
	printf("\n");
	va_end(ap);
	return (0);
}

int		main(int ac, char **av)
{
	char			*str = "diuxXcsefg";
	int				d = 123;
	int				i = 456;
	unsigned int	u = 345;
	unsigned int	x = 456;
	unsigned int	X = 567;
	char			c = 'c';
	char*			s = "string";
//					p = ;
	float			e = 678;
	float			f = 789;
	float			g = 890;
//					n = ;
	char				*str2 = "iiIIuU";
	int					i1 = 2147483647;
	int					i2 = -2147483648;
	long int			i3 = 9223372036854775807;
	long int			i4 = -9223372036854775807;
	unsigned int		i5 = 4294967295;
//	long unsigned int	i6 = 18446744073709551615;
	long unsigned int	i6 = 8446744073709551615;

	if (ac == 1)
	{
//		printf("%s : %d : %i : %u : %x : %X : %c : %s : %e : %f : %g\n", str, d, i, u, x, X, c, s, e, f, g);
//		ft_printf_test(str, d, i, u, x, X, c, s, e, f, g);
//		printf("%s : %i : %i : %li : %li : %u : %lu\n", str2, i1, i2, i3, i4, i5, i6);
//		ft_printf_test(str2, i1, i2, i3, i4, i5, i6);

		   printf("sdf\n");
		ft_printf("sdf\n\n");
		   printf("%i\n", 23);
		ft_printf("%i\n\n", 23);
		   long int k = -23;
		   printf("%li\n", k);
		ft_printf("%li\n\n", k);
		   printf("%i\n", -32);
		ft_printf("%i\n\n", -32);
		   printf("%li\n", 9223372036854775807);
		ft_printf("%li\n\n", 9223372036854775807);
		   printf("%c\n", 'f');
		ft_printf("%c\n\n", 'f');
		   printf("%s\n", "sdffhk");
		ft_printf("%s\n\n", "sdffhk");
		   printf("%u\n", 1221879);
		ft_printf("%u\n\n", 1221879);
		   printf("%x\n", 3287);
		ft_printf("%x\n\n", 3287);
		   printf("%lX\n", 9223372036854775807);
		ft_printf("%lX\n\n", 9223372036854775807);
		   printf("%p\n", "dfgdf");
		ft_printf("%p\n\n", "dfgdf");
	}
	return (0);
}

/*
conversions : cspdiuxX%
      flags : - 0 . *
conversions : nfge
      flags : l ll h hh # ' (space) +

%[arg_nbr$][flags 0,-,#,', ,+][width *][.precision *][length hh,h,ll,l,L,j,t,z][specifier d,i,u,x,X,c,s,p,%,e,f,g,n,E,F,G,a,A,C,S,o]
%          [flags 0,-        ][width *][.precision *]                          [specifier d,i,u,x,X,c,s,p,%                        ]
%          [flags     #,', ,+]                       [length hh,h,ll,l        ][specifier                   e,f,g,n                ]


		[flags]
		-		left-justify within the given field width
		0		left-pads the number with zeroes (0) instead of spaces, where
				padding is specified (see width sub-specifier)
	(	+		forces to precede the result with a plus or minus sign even for
				positive numbers)
	(	(space)	if no sign is going to be written, a blank space is inserted
				before the value)
	(	#		(o, x, X, a, A, e, E, f, F, g, G) used with (o, x or X) the
				value is preceded with 0, 0x or 0X for values different than
				zero. used with (e, E or f), it forces the written output to
				contain a decimal point even if no digits would follow. by
				default, if no digits follow, no decimal point is written. used
				with (g or G) the result is the same as with e or E but trailing
				zeros are not removed
	(	'		(d, u, i, f, F) used with d, u or i, or the integral portion of
				a float f or F, the decimal conversions are printed by groups of
				thousands separated by the non-monetary separator returned by
				localeconv(3) (ex 123456789 -> 123,456,789)
				
		[width]
		(nbr)	minimum number of characters to be printed. if the value to be
				printed is shorter than this number, the result is padded with
				blank spaces. The value is not truncated even if the result is
				larger
		*		the width is not specified in the format string, but as an
				additional integer value argument preceding the argument that
				has to be formatted
	
		[.precision]
		.nbr	fot integer specifiers (d,i,o,x,X) - precision specifies the
				minimum number of digits to be written. If the value to be
				written is shorter than this number, the result is padded with
				leading zeros. The value is not truncated even if the result is
				longer. A precision of 0 means that no character is written for
				the value 0. For e, E and f specifiers − this is the number of
				digits to be printed after the decimal point. For g and G
				specifiers − This is the maximum number of significant digits
				to be printed. For s − this is the maximum number of characters
				to be printed. By default all characters are printed until the
				ending null character is encountered. For c type − it has no
				effect. When no precision is specified, the default is 1. If the
				period is specified without an explicit value for precision, 0
				is assumed
		.*		the precision is not specified in the format string, but as an
				additional integer value argument preceding the argument that
				has to be formated

		[specifiers]
		c	char	character
		s	*char	string of characters
		p	*		pointer adress
		d	int		(or i) signed decimal integer
		i	int		(or d) signed decimal integer
		u	u int	unsigned decimal integer
		x	u int	unsigned hexadecimal integer
		X	u int	unsigned hexadecimal integer (capital letters)
	(	n	*int	nothing printed
	(	f	float	decimal floating point
	(	e	float	scientific notation (mantissa/exponent) using e
	(	g	float	uses the shorter of %e or %f
	((F	float
	((E	float	scientific notation (mantissa/exponent) using E
	((G	float	uses the shorter of %E or %f
	((o	int		signed octal
	((C	char	treated as c with l modifier
	((a	float
	((A	float
	((S	*char	treated as s with l modifier
	

p == long unsigned int

char		1bytes	8bits
short		2bytes	16bits
int			4bytes	32bits
long		8bytes	64bits
long long	8bytes	64bits

                 255                  -127 - +127                   00 [char]				[hhd, hhi, c]			[int]			[d( , h, hh), i( , h, hh), c]
               65535                -32768 - +32767                 01 [short]				[hd, hi]				[int]
          4294967295           -2147483648 - +2147483647            02 [int]				[d, i]					[int]
18446744073709551615  -9223372036854775808 - +9223372036854775807   04 [long]				[ld, li]				[long]			[d(l ,ll), i(l, ll)]
18446744073709551615  -9223372036854775808 - +9223372036854775807   04 [long long]			[lld, lli]				[long]
                 256                     0 - +255                   05 [unsigned char]		[hhu, hhx, hhX]			[unsigned int]	[u( , h, hh), x( , h, hh), X( , h, hh), p]
               65536                     0 - +65536                 06 [unsigned short]		[hu, hx, hX]			[unsigned int]
          4294967296                     0 - +4294967296            07 [unsigned int]		[u, x, X, p]			[unsigned int]
18446744073709551616                     0 - +18446744073709551616  09 [unsigned long]		[lu, lx, lX]			[unsigned long]	[s, u(l, ll), x(l, ll), X(l, ll)]
18446744073709551616                     0 - +18446744073709551616  09 [unsigned long long]	[llu, llx, llX]			[unsigned long]
18446744073709551616                     0 - +18446744073709551616  10 [char *]				[s, hhn]				[unsigned long]

18446744073709551616                     0 - +18446744073709551616  16 [double]				[e, le, f, lf, g, lg]	[]
18446744073709551616                     0 - +18446744073709551616  17 [wint_t]				[lc]					[]
18446744073709551616                     0 - +18446744073709551616  18 [wchar_t]			[ls]					[]
18446744073709551616                     0 - +18446744073709551616  11 [short *]			[hn]					[]
18446744073709551616                     0 - +18446744073709551616  12 [int *]				[n]						[]
18446744073709551616                     0 - +18446744073709551616  13 [long *]				[ln]					[]
18446744073709551616                     0 - +18446744073709551616  14 [long long *]		[lln]					[]

d	int						0	int
dhh	char					1	char
dh	short					2	short
dl	long					3	long
dll	long long				4	long long

i	int
ihh	char
ih	short
il	long
ill	long long

u	unsigned int			5	unsigned int
uhh	unsigned char			6	unsigned char
uh	unsigned short			7	unsigned short
ul	unsigned long			8	unsigned long
ull	unsigned long long		9	unsigned long long

x	unsigned int
xhh	unsigned char
xh	unsigned short
xl	unsigned long
xll	unsigned long long

X	unsigned int
Xhh	unsigned char
Xh	unsigned short
Xl	unsigned long
Xll	unsigned long long

c	char -> int
cl	wint_t					10	wint_t
s	char *					11	char *
sl	wchar_t *				12	wchar_t *
p	unsigned int
e	double					13	double
el	
f	double
fl	
g	double
gl	

n	int *					14	int *
nhh	char *
nh	short *					15	short *
nl	long *					16	long *
nll	long long *				17	long long *


	printf("char               %lu\n", sizeof(char));
	printf("short              %lu\n", sizeof(short));
	printf("int                %lu\n", sizeof(int));
	printf("long               %lu\n", sizeof(long));
	printf("long long          %lu\n", sizeof(long long));
	printf("unsigned char      %lu\n", sizeof(unsigned char));
	printf("unsigned short     %lu\n", sizeof(unsigned short));
	printf("unsigned int       %lu\n", sizeof(unsigned int));
	printf("unsigned long      %lu\n", sizeof(unsigned long));
	printf("unsigned long long %lu\n", sizeof(unsigned long long));
	printf("char *             %lu\n", sizeof(char *));
	printf("short *            %lu\n", sizeof(short *));
	printf("int *              %lu\n", sizeof(int *));
	printf("long *             %lu\n", sizeof(long *));
	printf("long long *        %lu\n", sizeof(long long *));
	printf("double             %lu\n", sizeof(double));
//	printf("wint_t             %lu\n", sizeof(wint_t));
//	printf("wchar_T            %lu\n", sizeof(wchar_t));

*/
