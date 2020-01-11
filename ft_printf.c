
#include "ft_printf.h"
#include <libc.h>

/*
**	va_list	ap;
**	char	*print;				| -contain the arg converted into a string
**	char	*type;				| -contain the specifier type to use
**								|  by va_arg
**	while s = next_word()		| -return the next sequence to be print
**								|  (either a string, or a conversion)
**		type = ft_specifier(&s)	| -return the type if it's a conversion, or "%",
**								|  or NULL if it's a string.
**								|  if convers0, rmvs length & specifier from s
**		if !type: ft_put_word()	| -print the string if it wasn't a conversion
**		while flag_*(s)			| -for each * present, expand it into s
**			ft_expand_star()	|  in order it appears
**		print = ft_convert()	| -convert the arg with its type,
**								|  then trsfm it into a str and rtrn the str
**		ft_flag_transform()		| -proceed all modification according to flags
**		ft_put_word(print)		| -print the string fully converted
**	return (length)				| -return the length of what was printed
**
** char *next_word(char *s);
** char *ft_specifier(char **s);
** int  ft_put_words(char *s);
** void flag_*(char *s);
** void ft_expand_star(int i, char **s);
** char *ft_convert(va_list ap, char *type);
** char *ft_flag_transform(char *s, char *print);
*/

int		ft_printf(char *string, ...)
{
//	char	*print;
//	char	*type;
//	int		length;
//	va_list	ap;
//
//	length = 0;
//	va_start(ap, string);
//	while ((s = next_word(str)) != NULL)
//	{
//		if (!(type = ft_specifier(&s)))
//			lentgh += ft_put_word(s);
//		while (flag_*(s))
//			ft_expand_star(va_arg(ap, int), &s);
//		if (*type == '%')
//			print = ft_strdup("%");
//		else
//			print = ft_convert(ap, type);
//		print = ft_flag_transform(s, print);
//		length += ft_put_word(print);
//	}
//	return (length)
//}

/*
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

//	ft_flag_transform()
//	{
//		if ((i = flag_p(&s)))
//			print = ft_precision(i, print);
//		if ((i = flag_w(s)))
//		{
//			if (flag_-(&s))
//				print = ft_rpadd(i, print);
//			else if (flag_0(&s))
//				print = ft_lpadd(i, print, '0');
//			else
//				print = ft_lpadd(i, print, ' ');
//		}
	//	if (flag_+(s))								//
	//	else if (flag_space(s))						//
	//	if (flag_'(s))								//
	//	if (flag_#(s))								//
	//		print = ft_alternate_form(print)		//                                           
	//	}

	t_prist	*lst;
	va_list	ap;

	va_start(ap, string);
	while (*string != '\0')
	{
		if (*string == 's')
			printf("string %s\n", va_arg(ap, char *));
		if (*string == 'd')
			printf("int %d\n", va_arg(ap, int));
		if (*string == 'c')
			printf("char %c\n", va_arg(ap, int));
		string++;
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

	s = "csd";
	c = 'p';
	str = "bravo";
	i = 6;
	printf("%s-%s-%c-%i\n\n", s, str, c, i);
	ft_printf(s, c, str, i);
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
                 256                     0 - +255                   05 [unsigned char]		[hhu, hhx, hhX]			[unsigned long]	[u( , h, hh, l, ll), x( , h, hh, l, ll), X( , h, hh, l, ll), p]
               65536                     0 - +65536                 06 [unsigned short]		[hu, hx, hX]			[unsigned long]
          4294967296                     0 - +4294967296            07 [unsigned int]		[u, x, X, p]			[unsigned long]
18446744073709551616                     0 - +18446744073709551616  09 [unsigned long]		[lu, lx, lX]			[unsigned long]
18446744073709551616                     0 - +18446744073709551616  09 [unsigned long long]	[llu, llx, llX]			[unsigned long]
18446744073709551616                     0 - +18446744073709551616  10 [char *]				[s, hhn]				[char *]		[s]

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
