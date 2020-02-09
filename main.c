#include "ft_printf.h"
#include <libc.h>
#include <locale.h>

int		main(void)
{
	char	*str;
	char	c;
	int		i;

	setlocale(LC_ALL, "en_US.UTF-8");
	str = "bravo";
	c = 'c';
	i = 6;

		printf("-----------------------------------------------\n");
		printf("-                   BASICS                    -\n");
		printf("-                                             -\n");
		printf("- %%[flag][width][.precision][length]specifier -\n");
		printf("-                                             -\n");
		printf("- conversions : cspdiuxX%%                     -\n");
		printf("-       flags : -,0,.,*                       -\n");
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

	//	printf("(\"%%.10%%\")      ft : ");	ft_printf("'%.10%'\n");
		printf("(\"%%.10%%\")         : ");	   printf("'%.10%'\n"); printf("\n");

	//	printf("(\"%%10%%\")       ft : ");	ft_printf("'%10%'\n");
		printf("(\"%%10%%\")          : ");	   printf("'%10%'\n"); printf("\n");

	//	printf("(\"%%-10%%\")      ft : ");	ft_printf("'%-10%'\n");
		printf("(\"%%-10%%\")         : ");	   printf("'%-10%'\n"); printf("\n");

	//	printf("(\"%%010%%\")      ft : ");	ft_printf("'%010%'\n");
		printf("(\"%%010%%\")         : ");	   printf("'%010%'\n"); printf("\n");

	//	printf("(\"%%-010%%\")     ft : ");	ft_printf("'%-010%'\n");
		printf("(\"%%-010%%\")        : ");	   printf("'%-010%'\n"); printf("\n");

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

	//	printf("(\"%%X\",123456)  ft : ");	ft_printf("%X\n", 123456);
		printf("(\"%%X\",123456)     : ");	   printf("%X\n", 123456); printf("\n");

	//	printf("(\"%%X\",0x1E240) ft : ");	ft_printf("%X\n", 0x1E240);
		printf("(\"%%X\",0x1E240)    : ");	   printf("%X\n", 0x1E240); printf("\n");

	//	printf("(\"%%i\",0x1E240) ft : ");	ft_printf("%i\n", 0x1E240);
		printf("(\"%%i\",0x1E240)    : ");	   printf("%i\n", 0x1E240); printf("\n");

		printf("-----------------------------------------------\n");
		printf("- flags : -0.*                                -\n");
		printf("- taille de champ minimale                    -\n");
		printf("-----------------------------------------------\n\n");

		printf("- taille de champ minimale --------------------\n\n");

	//	printf("(\"%%3s\",\"a\")           ft : ");	ft_printf("'%3s'\n", "a");
		printf("(\"%%3s\",\"a\")              : ");	   printf("'%3s'\n", "a"); printf("\n");

	//	printf("(\"%%3s\",\"abcd\")        ft : ");	ft_printf("'%3s'\n", "abcd");
		printf("(\"%%3s\",\"abcd\")           : ");	   printf("'%3s'\n", "abcd"); printf("\n");

	//	printf("(\"%%3i\",12)            ft : ");	ft_printf("'%3i'\n", 12);
		printf("(\"%%3i\",12)               : ");	   printf("'%3i'\n", 12); printf("\n");

	//	printf("(\"%%2i\",12)            ft : ");	ft_printf("'%2i'\n", 12);
		printf("(\"%%2i\",12)               : ");	   printf("'%2i'\n", 12); printf("\n");

	//	printf("(\"%%1i\",12)            ft : ");	ft_printf("'%1i'\n", 12);
		printf("(\"%%1i\",12)               : ");	   printf("'%1i'\n", 12); printf("\n");

	//	printf("(\"%%0i\",0)             ft : ");	ft_printf("'%0i'\n", 0);
		printf("(\"%%0i\",0)                : ");	   printf("'%0i'\n", 0); printf("\n");

	//	printf("(\"%%6i\",-456)          ft : ");	ft_printf("'%6i'\n", -456);
		printf("(\"%%6i\",-456)             : ");	   printf("'%6i'\n", -456); printf("\n");

	//	printf("(\"%%6%%\")               ft : ");	ft_printf("'%6%'\n");
		printf("(\"%%6%%\")                  : ");	   printf("'%6%'\n"); printf("\n");

		printf("- flag - --------------------------------------\n\n");

	//	printf("(\"%%-3s\",\"a\")          ft : ");	ft_printf("'%-3s'\n", "a");
		printf("(\"%%-3s\",\"a\")             : ");	   printf("'%-3s'\n", "a"); printf("\n");

	//	printf("(\"%%-9s\",\"a\")          ft : ");	ft_printf("'%-9s'\n", "a");
		printf("(\"%%-9s\",\"a\")             : ");	   printf("'%-9s'\n", "a"); printf("\n");

	//	printf("(\"%%-1s\",\"ab\")         ft : ");	ft_printf("'%-1s'\n", "ab");
		printf("(\"%%-1s\",\"ab\")            : ");	   printf("'%-1s'\n", "ab"); printf("\n");

	//	printf("(\"%%-2s\",\"ab\")         ft : ");	ft_printf("'%-2s'\n", "ab");
		printf("(\"%%-2s\",\"ab\")            : ");	   printf("'%-2s'\n", "ab"); printf("\n");

	//	printf("(\"%%-3s\",\"ab\")         ft : ");	ft_printf("'%-3s'\n", "ab");
		printf("(\"%%-3s\",\"ab\")            : ");	   printf("'%-3s'\n", "ab"); printf("\n");

	//	printf("(\"%%-3i\",3)            ft : ");	ft_printf("'%-3i'\n", 3);
		printf("(\"%%-3i\",3)               : ");	   printf("'%-3i'\n", 3); printf("\n");

	//	printf("(\"%%-3i\",123456)       ft : ");	ft_printf("'%-3i'\n", 123456);
		printf("(\"%%-3i\",123456)          : ");	   printf("'%-3i'\n", 123456); printf("\n");

		printf("- flag 0 (diouxX%%)------------------------------\n");
		printf("-        \n");

	//	printf("(\"%%03i\",1)            ft : ");	ft_printf("'%03i'\n", 1);
		printf("(\"%%03i\",1)               : ");	   printf("'%03i'\n", 1); printf("\n");

	//	printf("(\"%%03u\",1)            ft : ");	ft_printf("'%03u'\n", 1);
		printf("(\"%%03u\",1)               : ");	   printf("'%03u'\n", 1); printf("\n");

	//	printf("(\"%%03x\",1)            ft : ");	ft_printf("'%03x'\n", 1);
		printf("(\"%%03x\",1)               : ");	   printf("'%03x'\n", 1); printf("\n");

	//	printf("(\"%%03%%\")              ft : ");	ft_printf("'%03%'\n");
		printf("(\"%%03%%\")                 : ");	   printf("'%03%'\n"); printf("\n");

	//	printf("(\"%%0%%\")               ft : ");	ft_printf("'%0%'\n");
		printf("(\"%%0%%\")                  : ");	   printf("'%0%'\n"); printf("\n");

		printf("- flag . (diouxXs) ----------------------------------------------------------\n");
		printf("-        if the . is not followed by a number, the value is 0\n");
		printf("-        with arg value of 0, precision of 0 print nothing\n");
		printf("-        with numbers (diouxX), gives the minimum number of digit to appear\n");
		printf("-          if precision > nbr, it's preceded by '0'\n");
		printf("-          if nbr < 0, '-' is not counted in precision\n");
		printf("-          (length with '-' is (length(nbr or precision) + 1)'\n");
		printf("-          if 0 flag is given (for width or precision) it's ignored\n");
		printf("-        with strings (s), gives the maximum number of characters to be print\n");
		printf("-          if precision > length(s), it's not preceded by '0'\n");
		printf("-        precision is calculated before width\n");
		printf("\n");

	//	printf("(\"%%.5s\",\"12\")         ft : ");	ft_printf("'%.5s'\n", "12");
		printf("(\"%%.5s\",\"12\")            : ");	   printf("'%.5s'\n", "12"); printf("\n");

	//	printf("(\"%%.5s\",\"12345678\")   ft : ");	ft_printf("'%.5s'\n", "12345678");
		printf("(\"%%.5s\",\"12345678\")      : ");	   printf("'%.5s'\n", "12345678"); printf("\n");

	//	printf("(\"%%12.5s\",\"12345678\") ft : ");	ft_printf("'%12.5s'\n", "12345678");
		printf("(\"%%12.5s\",\"12345678\")    : ");	   printf("'%12.5s'\n", "12345678"); printf("\n");

	//	printf("(\"%%.5i\",12)           ft : ");	ft_printf("'%.5i'\n", 12);
		printf("(\"%%.5i\",12)              : ");	   printf("'%.5i'\n", 12); printf("\n");

	//	printf("(\"%%.7X\",8645)         ft : ");	ft_printf("'%.7X'\n", 8645);
		printf("(\"%%.7X\",8645)            : ");	   printf("'%.7X'\n", 8645); printf("\n");

	//	printf("(\"%%7.7X\",8645)        ft : ");	ft_printf("'%7.7X'\n", 8645);
		printf("(\"%%7.7X\",8645)           : ");	   printf("'%7.7X'\n", 8645); printf("\n");

	//	printf("(\"%%9.7X\",8645)        ft : ");	ft_printf("'%9.7X'\n", 8645);
		printf("(\"%%9.7X\",8645)           : ");	   printf("'%9.7X'\n", 8645); printf("\n");

	//	printf("(\"%%-9.7X\",8645)       ft : ");	ft_printf("'%-9.7X'\n", 8645);
		printf("(\"%%-9.7X\",8645)          : ");	   printf("'%-9.7X'\n", 8645); printf("\n");

	//	printf("(\"%%7.9X\",8645)        ft : ");	ft_printf("'%7.9X'\n", 8645);
		printf("(\"%%7.9X\",8645)           : ");	   printf("'%7.9X'\n", 8645); printf("\n");

	//	printf("(\"%%.0i\",0)            ft : ");	ft_printf("'%.0i'\n", 0);
		printf("(\"%%.0i\",0)               : ");	   printf("'%.0i'\n", 0); printf("\n");

	//	printf("(\"%%.0X\",0)            ft : ");	ft_printf("'%.0X'\n", 0);
		printf("(\"%%.0X\",0)               : ");	   printf("'%.0X'\n", 0); printf("\n");

	//	printf("(\"%%.i\",0)             ft : ");	ft_printf("'%.i'\n", 0);
		printf("(\"%%.i\",0)                : ");	   printf("'%.i'\n", 0); printf("\n");

	//	printf("(\"%%i\",0)              ft : ");	ft_printf("'%i'\n", 0);
		printf("(\"%%i\",0)                 : ");	   printf("'%i'\n", 0); printf("\n");

	//	printf("(\"%%010.7X\",8645)      ft : ");	ft_printf("'%010.7X'\n", 8645);
		printf("(\"%%010.7X\",8645)         : ");	   printf("'%010.7X'\n", 8645); printf("\n");

	//	printf("(\"%%10.7X\",8645)       ft : ");	ft_printf("'%10.7X'\n", 8645);
		printf("(\"%%10.7X\",8645)          : ");	   printf("'%10.7X'\n", 8645); printf("\n");

	//	printf("(\"%%-10.7X\",8645)      ft : ");	ft_printf("'%-10.7X'\n", 8645);
		printf("(\"%%-10.7X\",8645)         : ");	   printf("'%-10.7X'\n", 8645); printf("\n");

	//	printf("(\"%%-.7i\",8645)        ft : ");	ft_printf("'%-.7i'\n", 8645);
		printf("(\"%%-.7i\",8645)           : ");	   printf("'%-.7i'\n", 8645); printf("\n");

	//	printf("(\"%%.7i\",-8645)        ft : ");	ft_printf("'%.7i'\n", -8645);
		printf("(\"%%.7i\",-8645)           : ");	   printf("'%.7i'\n", -8645); printf("\n");

	//	printf("(\"%%.07i\",8645)        ft : ");	ft_printf("'%.07i'\n", 8645);
		printf("(\"%%.07i\",8645)           : ");	   printf("'%.07i'\n", 8645); printf("\n");

	//	printf("(\"%%.7%%\")              ft : ");	ft_printf("'%.7%'\n");
		printf("(\"%%.7%%\")                 : ");	   printf("'%.7%'\n"); printf("\n");

		printf("- flag * --------------------------------------\n\n");

	//	printf("(\"%%*i\",3,1)           ft : ");	ft_printf("'%*i'\n", 3, 1);
		printf("(\"%%*i\",3,1)              : ");	   printf("'%*i'\n", 3, 1); printf("\n");

	//	printf("(\"%%-*i\",3,1)          ft : ");	ft_printf("'%-*i'\n", 3, 1);
		printf("(\"%%-*i\",3,1)             : ");	   printf("'%-*i'\n", 3, 1); printf("\n");

	//	printf("(\"%%*i-%%*i\",1,2,3,4)   ft : ");	ft_printf("'%*i-%*i'\n", 1, 2, 3, 4);
		printf("(\"%%*i-%%*i\",1,2,3,4)      : ");	   printf("'%*i-%*i'\n", 1, 2, 3, 4); printf("\n");

	//	printf("(\"%%*i-%%*i\",0,1,2,3)   ft : ");	ft_printf("'%*i-%*i'\n", 0, 1, 2, 3);
		printf("(\"%%*i-%%*i\",0,1,2,3)      : ");	   printf("'%*i-%*i'\n", 0, 1, 2, 3); printf("\n");

	//	printf("(\"%%.*i-%%.*i\",0,1,2,3) ft : ");	ft_printf("'%.*i-%.*i'\n", 0, 1, 2, 3);
		printf("(\"%%.*i-%%.*i\",0,1,2,3)    : ");	   printf("'%.*i-%.*i'\n", 0, 1, 2, 3); printf("\n");

	//	printf("(\"%%3.2i\",1)           ft : ");	ft_printf("'%3.2i'\n", 1);
		printf("(\"%%3.2i\",1)              : ");	   printf("'%3.2i'\n", 1); printf("\n");

	//	printf("(\"%%*.*i\",3,2,1)       ft : ");	ft_printf("'%*.*i'\n", 3, 2, 1);
		printf("(\"%%*.*i\",3,2,1)          : ");	   printf("'%*.*i'\n", 3, 2, 1); printf("\n");

		printf("-----------------------------------------------\n");
		printf("-              TESTS REPETITIONS              -\n");
		printf("-               nbr of [#0-+ ']               -\n");
		printf("-----------------------------------------------\n\n");

		printf("(\"%%i'\", 33333)          : ");	   printf("'%i'\n", 33333); printf("\n");

		printf("(\"%%.0f\", 33333.0)       : ");	   printf("'%.0f'\n", 33333.0); printf("\n");

		printf("(\"%%#.0f\", 33333.0)      : ");	   printf("'%#.0f'\n", 33333.0); printf("\n");

		printf("(\"%%08i\", 33333)         : ");	   printf("'%08i'\n", 33333); printf("\n");

		printf("(\"%%-8i\", 33333)         : ");	   printf("'%-8i'\n", 33333); printf("\n");

		printf("(\"%%+i\", 33333)          : ");	   printf("'%+i'\n", 33333); printf("\n");

		printf("(\"%% i\", 33333)          : ");	   printf("'% i'\n", 33333); printf("\n");

		printf("(\"%%'i\", 33333)          : ");	   printf("'%'i'\n", 33333); printf("\n");

		printf("- repetition with ''' -------------------------\n");
		printf("- (repeatable additionable unordered) rau -----\n\n");

		printf("(\"%%''''i\", 33333)       : ");	   printf("'%''''i'\n", 33333); printf("\n");

		printf("(\"%%'#.0f\", 33333.0)     : ");	   printf("'%'#.0f'\n", 33333.0); printf("\n");

		printf("(\"%%#'.0f\", 33333.0)     : ");	   printf("'%#'.0f'\n", 33333.0); printf("\n");

		printf("(\"%%'#'.0f\", 33333.0)    : ");	   printf("'%'#'.0f'\n", 33333.0); printf("\n");

		printf("(\"%%'08i\", 33333)        : ");	   printf("'%'08i'\n", 33333); printf("\n");

		printf("(\"%%0'8i\", 33333)        : ");	   printf("'%0'8i'\n", 33333); printf("\n");

		printf("(\"%%'0'8i\", 33333)       : ");	   printf("'%'0'8i'\n", 33333); printf("\n");

		printf("(\"%%'-8i\", 33333)        : ");	   printf("'%'-8i'\n", 33333); printf("\n");

		printf("(\"%%-'8i\", 33333)        : ");	   printf("'%-'8i'\n", 33333); printf("\n");

		printf("(\"%%'-'8i\", 33333)       : ");	   printf("'%'-'8i'\n", 33333); printf("\n");

		printf("(\"%%'+i\", 33333)         : ");	   printf("'%'+i'\n", 33333); printf("\n");

		printf("(\"%%+'i\", 33333)         : ");	   printf("'%+'i'\n", 33333); printf("\n");

		printf("(\"%%'+'i\", 33333)        : ");	   printf("'%'+'i'\n", 33333); printf("\n");

		printf("(\"%%' i\", 33333)         : ");	   printf("'%' i'\n", 33333); printf("\n");

		printf("(\"%% 'i\", 33333)         : ");	   printf("'% 'i'\n", 33333); printf("\n");

		printf("(\"%%' 'i\", 33333)        : ");	   printf("'%' 'i'\n", 33333); printf("\n");

		printf("- repetition with ' ' -------------------------\n");
		printf("- '+' and ' ' not compatible ------------------\n");
		printf("- rau -----------------------------------------\n\n");

		printf("(\"%%    i\", 33333)       : ");	   printf("'%    i'\n", 33333); printf("\n");

		printf("(\"%% #.0f\", 33333.0)     : ");	   printf("'% #.0f'\n", 33333.0); printf("\n");

		printf("(\"%%# .0f\", 33333.0)     : ");	   printf("'%# .0f'\n", 33333.0); printf("\n");

		printf("(\"%% # .0f\", 33333.0)    : ");	   printf("'% # .0f'\n", 33333.0); printf("\n");

		printf("(\"%% 08i\", 33333)        : ");	   printf("'% 08i'\n", 33333); printf("\n");

		printf("(\"%%0 8i\", 33333)        : ");	   printf("'%0 8i'\n", 33333); printf("\n");

		printf("(\"%% 0 8i\", 33333)       : ");	   printf("'% 0 8i'\n", 33333); printf("\n");

		printf("(\"%% -8i\", 33333)        : ");	   printf("'% -8i'\n", 33333); printf("\n");

		printf("(\"%%- 8i\", 33333)        : ");	   printf("'%- 8i'\n", 33333); printf("\n");

		printf("(\"%% - 8i\", 33333)       : ");	   printf("'% - 8i'\n", 33333); printf("\n");

		printf("(\"%% 'i\", 33333)         : ");	   printf("'% 'i'\n", 33333); printf("\n");

		printf("(\"%%' i\", 33333)         : ");	   printf("'%' i'\n", 33333); printf("\n");

		printf("(\"%% ' i\", 33333)        : ");	   printf("'% ' i'\n", 33333); printf("\n");

		printf("- repetition with '-' -------------------------\n");
		printf("- '0' and '-' not compatible ------------------\n");
		printf("- rau -----------------------------------------\n\n");

		printf("(\"%%----i\", 33333)       : ");	   printf("'%----i'\n", 33333); printf("\n");

		printf("(\"%%-#.0f\", 33333.0)     : ");	   printf("'%-#.0f'\n", 33333.0); printf("\n");

		printf("(\"%%#-.0f\", 33333.0)     : ");	   printf("'%#-.0f'\n", 33333.0); printf("\n");

		printf("(\"%%-#-.0f\", 33333.0)    : ");	   printf("'%-#-.0f'\n", 33333.0); printf("\n");

		printf("(\"%%-+8i\", 33333)        : ");	   printf("'%-+8i'\n", 33333); printf("\n");

		printf("(\"%%+-8i\", 33333)        : ");	   printf("'%+-8i'\n", 33333); printf("\n");

		printf("(\"%%-+-8i\", 33333)       : ");	   printf("'%-+-8i'\n", 33333); printf("\n");

		printf("(\"%%- i\", 33333)         : ");	   printf("'%- i'\n", 33333); printf("\n");

		printf("(\"%% -i\", 33333)         : ");	   printf("'% -i'\n", 33333); printf("\n");

		printf("(\"%%- -i\", 33333)        : ");	   printf("'%- -i'\n", 33333); printf("\n");

		printf("(\"%%-'i\", 33333)         : ");	   printf("'%-'i'\n", 33333); printf("\n");

		printf("(\"%%'-i\", 33333)         : ");	   printf("'%'-i'\n", 33333); printf("\n");

		printf("(\"%%-'-i\", 33333)        : ");	   printf("'%-'-i'\n", 33333); printf("\n");

		printf("- repetition with '+' -------------------------\n");
		printf("- '+' and ' ' not compatible ------------------\n");
		printf("- rau -----------------------------------------\n\n");

		printf("(\"%%++++i\", 33333)       : ");	   printf("'%++++i'\n", 33333); printf("\n");

		printf("(\"%%+#.0f\", 33333.0)     : ");	   printf("'%+#.0f'\n", 33333.0); printf("\n");

		printf("(\"%%#+.0f\", 33333.0)     : ");	   printf("'%#+.0f'\n", 33333.0); printf("\n");

		printf("(\"%%+#+.0f\", 33333.0)    : ");	   printf("'%+#+.0f'\n", 33333.0); printf("\n");

		printf("(\"%%+08i\", 33333)        : ");	   printf("'%+08i'\n", 33333); printf("\n");

		printf("(\"%%0+8i\", 33333)        : ");	   printf("'%0+8i'\n", 33333); printf("\n");

		printf("(\"%%+0+8i\", 33333)       : ");	   printf("'%+0+8i'\n", 33333); printf("\n");

		printf("(\"%%+-8i\", 33333)        : ");	   printf("'%+-8i'\n", 33333); printf("\n");

		printf("(\"%%-+8i\", 33333)        : ");	   printf("'%-+8i'\n", 33333); printf("\n");

		printf("(\"%%+-+8i\", 33333)       : ");	   printf("'%+-+8i'\n", 33333); printf("\n");

		printf("(\"%%+'i\", 33333)         : ");	   printf("'%+'i'\n", 33333); printf("\n");

		printf("(\"%%'+i\", 33333)         : ");	   printf("'%'+i'\n", 33333); printf("\n");

		printf("(\"%%+'+i\", 33333)        : ");	   printf("'%+'+i'\n", 33333); printf("\n");

		printf("- repetition with '#' -------------------------\n");
		printf("- rau -----------------------------------------\n\n");

		printf("(\"%%####f\", 33333.0)     : ");	   printf("'%####f'\n", 33333.0); printf("\n");

		printf("(\"%%#+.0f\", 33333.0)     : ");	   printf("'%#+.0f'\n", 33333.0); printf("\n");

		printf("(\"%%+#.0f\", 33333.0)     : ");	   printf("'%+#.0f'\n", 33333.0); printf("\n");

		printf("(\"%%#+#.0f\", 33333.0)    : ");	   printf("'%#+#.0f'\n", 33333.0); printf("\n");

		printf("(\"%%#08f\", 33333.0)      : ");	   printf("'%#08f'\n", 33333.0); printf("\n");

		printf("(\"%%0#8f\", 33333.0)      : ");	   printf("'%0#8f'\n", 33333.0); printf("\n");

		printf("(\"%%#0#8f\", 33333.0)     : ");	   printf("'%#0#8f'\n", 33333.0); printf("\n");

		printf("(\"%%#-8f\", 33333.0)      : ");	   printf("'%#-8f'\n", 33333.0); printf("\n");

		printf("(\"%%-#8f\", 33333.0)      : ");	   printf("'%-#8f'\n", 33333.0); printf("\n");

		printf("(\"%%#-#8f\", 33333.0)     : ");	   printf("'%#-#8f'\n", 33333.0); printf("\n");

		printf("(\"%%#'f\", 33333.0)       : ");	   printf("'%#'f'\n", 33333.0); printf("\n");

		printf("(\"%%'#f\", 33333.0)       : ");	   printf("'%'#f'\n", 33333.0); printf("\n");

		printf("(\"%%#'#f\", 33333.0)      : ");	   printf("'%#'#f'\n", 33333.0); printf("\n");

		printf("(\"%%# f\", 33333.0)       : ");	   printf("'%# f'\n", 33333.0); printf("\n");

		printf("(\"%% #f\", 33333.0)       : ");	   printf("'% #f'\n", 33333.0); printf("\n");

		printf("(\"%%# #f\", 33333.0)      : ");	   printf("'%# #f'\n", 33333.0); printf("\n");

		printf("- repetition with '0' -------------------------\n");
		printf("- '0' and '-' not compatible ------------------\n");
		printf("- rau -----------------------------------------\n\n");

		printf("(\"%%0000i\", 33333)       : ");	   printf("'%0000i'\n", 33333); printf("\n");

		printf("(\"%%0#.0f\", 33333.0)     : ");	   printf("'%0#.0f'\n", 33333.0); printf("\n");

		printf("(\"%%#0.0f\", 33333.0)     : ");	   printf("'%#0.0f'\n", 33333.0); printf("\n");

		printf("(\"%%0#0.0f\", 33333.0)    : ");	   printf("'%0#0.0f'\n", 33333.0); printf("\n");

		printf("(\"%%0+8i\", 33333)        : ");	   printf("'%0+8i'\n", 33333); printf("\n");

		printf("(\"%%+08i\", 33333)        : ");	   printf("'%+08i'\n", 33333); printf("\n");

		printf("(\"%%0+08i\", 33333)       : ");	   printf("'%0+08i'\n", 33333); printf("\n");

		printf("(\"%%0 i\", 33333)         : ");	   printf("'%0 i'\n", 33333); printf("\n");

		printf("(\"%% 0i\", 33333)         : ");	   printf("'% 0i'\n", 33333); printf("\n");

		printf("(\"%%0 0i\", 33333)        : ");	   printf("'%0 0i'\n", 33333); printf("\n");

		printf("(\"%%0'i\", 33333)         : ");	   printf("'%0'i'\n", 33333); printf("\n");

		printf("(\"%%'0i\", 33333)         : ");	   printf("'%'0i'\n", 33333); printf("\n");

		printf("(\"%%0'0i\", 33333)        : ");	   printf("'%0'0i'\n", 33333); printf("\n");


	//	printf("-----------------------------------------------\n");
	//	printf("-                    BONUS                    -\n");
	//	printf("- conversions : nfge                          -\n");
	//	printf("-       flags : l,ll,h,hh,#,', ,+             -\n");
	//	printf("-----------------------------------------------\n\n");

	//	printf("(\"%%#X\",8645)      : ");
	//	printf("'%#X' \n", 8645);
	//
	//	printf("(\"%%#.7X\",8645)    : ");
	//	printf("'%#.7X' \n", 8645);
	//
	//	printf("(\"%%#010.7X\",8645) : ");
	//	printf("'%#010.7X' \n", 8645);
	//
	//	printf("(\"%%#10.7X\",8645)  : ");
	//	printf("'%#10.7X' \n", 8645);
	//
	//	printf("(\"%%#10X\",8645)    : ");
	//	printf("'%#10X' \n", 8645);
	//
	//	printf("(\"%%#.10X\",8645)   : ");
	//	printf("'%#.10X' \n", 8645);
	//
	//	printf("(\"%%#10.10X\",8645) : ");
	//	printf("'%#10.10X' \n", 8645);
	//
	//	printf("(\"%%#010X\",8645)   : ");
	//	printf("'%#010X' \n", 8645);

	//	printf("-----------------------------------------------\n");
	//	printf("-                     ADD                     -\n");
	//	printf("-       flags : $                             -\n");
	//	printf("-----------------------------------------------\n\n");

	//	printf("(\"%%1$*2$i\",3,2) ft : ");	ft_printf("'%1$*2$i'\n", 3, 2);
	//	printf("(\"%%1$*2$i\",3,2)    : ");	   printf("'%1$*2$i'\n", 3, 2); printf("\n");

	//	printf("(\"%%2$*1$i\",3,2) ft : ");	ft_printf("'%2$*1$i'\n", 3, 2);
	//	printf("(\"%%2$*1$i\",3,2)    : ");	   printf("'%2$*1$i'\n", 3, 2); printf("\n");

		printf("-----------------------------------------------\n");
		printf("- errors                                      -\n");
		printf("-----------------------------------------------\n\n");

	//	printf("(\"%%i\",3,2)        ft : ");	ft_printf("'%i'", 3, 2);
		printf("(\"%%i\",3,2)           : ");/*	   printf("'%i'", 3, 2);*/ printf(" too much argments\n\n");

	//	printf("(\"%%i-%%i\",3)       ft : ");	ft_printf("'%i-%i'", 3);
		printf("(\"%%i-%%i\",3)          : ");/*	   printf("'%i-%i'", 3);*/ printf(" not enough arguments\n\n");

	//	printf("(\"%%-03i\",1)       ft : ");	ft_printf("'%-03i'", 1);
  		printf("(\"%%-03i\",1)          : ");/*	   printf("'%-03i'", 1);*/ printf(" flag 0 is ignored when - is present\n\n");

	//	printf("(\"%%010s\",str)     ft : ");	ft_printf("'%010s'", str);
		printf("(\"%%010s\",str)        : ");/*	   printf("'%010s'", str);*/ printf(" flag 0 has undefined behavior with s specifier\n\n");

	//	printf("(\"%%010c\",c)       ft : ");	ft_printf("'%010c'", c);
		printf("(\"%%010c\",c)          : ");/*	   printf("'%010c'", c);*/ printf(" flag 0 has undefined behavior with c specifier\n\n");

	//	printf("(\"%%03p\",str)      ft : ");		ft_printf("'%03p'\n", str);
		printf("(\"%%03p\",str)         : ");/*	   printf("'%03p'\n", str);*/ printf(" flag 0 has undefined behavior with p specifier\n\n");

	//	printf("(\"%%.-7X\",8645)    ft : ");	ft_printf("'%.-7X'", 8645);
		printf("(\"%%.-7X\",8645)       : ");/*	   printf("'%.-7X'", 8645);*/ printf(" invalid flag - for .precision\n\n");

	//	printf("(\"%%\",8645)        ft : ");	ft_printf("'%'", 8645);
		printf("(\"%%\",8645)           : ");/*	   printf("'%'", 8645);*/ printf(" missing conversion specifier\n\n");

	//	printf("(\"%%2$i-%%i\",3,2)   ft : ");	ft_printf("'%2$i-%i'\n", 3, 2);
		printf("(\"%%2$i-%%i\",3,2)      : ");/*	   printf("'%2$i-%i'", 3, 2);*/ printf(" cannot mix positioned and non-positioned args\n\n");

//		printf("(\"%% +i\", 33          : ");	ft_printf("'% +i'\n", 33);
		printf("(\"%% +i\", 33          : ");/*	   printf("'% +i'\n", 33);*/ printf(" flag ' ' is ignored when '+' is present\n\n");

//		printf("(\"%%-0i\", 33          : ");	ft_printf("'%-+i'\n", 33);
		printf("(\"%%-0i\", 33          : ");/*	   printf("'%-0i'\n", 33);*/ printf(" flag '0' is ignored when '-' is present\n\n");


	return (0);
}

/*
		int flag:                  pw+ '#-0
		00000000 00000000 00000000 00000001 == 1	'0'
		00000000 00000000 00000000 00000010 == 2	'-'
		00000000 00000000 00000000 00000100 == 4	'#'
		00000000 00000000 00000000 00001000 == 8	'''
		00000000 00000000 00000000 00010000 == 16	' '
		00000000 00000000 00000000 00100000 == 32	'+'
		00000000 00000000 00000000 01000000 == 64	'*' width
		00000000 00000000 00000000 10000000 == 128	'*' precision
		
		typedef struct		s_prist
		{
			char			*str;
			int				flag;		// default 0    ; [0-#' +**] binary
			int				width;		// default 0    ;
			int				prec;		// default 0    ; precision
			char			*length;	// default "\0" ;
			char 			spec;		// default 0    ; specifier
			char			*arg;		// default "\0" ;
			int				p_nb;		// default 0    ; print_nb : order in which to print (order it was found in string)
			int				a_nb;		// default 0    ;   arg_nb : number of the corresponding argument (for flag $)
			struct s_prist	*next;
		}					t_prist;
		
		("2 1 3 4 3", 1, 2, 3, 4)
		
		ft_error(int err)
		ft_store("%i truc %-10d machin\n")
			ft_split_print(str)
				prist->str = "%i";
					ft_fill_lst(prist)
						prist->flag;		// default = 0
						prist->width;		// default = 0
						prist->prec;		// default = 0
						prist->length;
						prist->spec;
						prist->p_nb;
						prist->a_nb;		// if not $ == p_nb
				prist->str = " truc ";
					ft_fill_lst(prist)
						...					// if str start without % it means it can be printed as a string directly
				prist->str = "%-10d";
					ft_fill_lst...
				prist->str = " machin\n";
					ft_fill_lst...
			return
			{{str; flag; width; precision; length; specifier; p_nb 1; a_nb 2},
			 {str; flag; width; precision; length; specifier; p_nb 2; a_nb 1},
			 {str; flag; width; precision; length; specifier; p_nb 3; a_nb 3},
			 {str; flag; width; precision; length; specifier; p_nb 4; a_nb 4},
			 {str; flag; width; precision; length; specifier; p_nb 5; a_nb 3}}
		
		ft_sort_by_arg
		{{str; flag; width; precision; length; specifier; p_nb 2; a_nb 1},
		 {str; flag; width; precision; length; specifier; p_nb 1; a_nb 2},
		 {str; flag; width; precision; length; specifier; p_nb 3; a_nb 3},
		 {str; flag; width; precision; length; specifier; p_nb 5; a_nb 3},
		 {str; flag; width; precision; length; specifier; p_nb 4; a_nb 4}}
		
		ft_add_arg
		if lst->str[o] != '\%'  rerun without looking for argument
		if lst->flag == *  rerun for next argument but same list element
										[fl][w][p]  or          or
			%i		,1		-> '1'		[]  [0][0]  [  ][0][0]  []  [0][0]
			%*i		,3,1	-> '  1'	[*] [0][0]  [* ][0][0]  [w] [0][0]
			%.*i	,2,1	-> '01'		[*] [0][0]  [ *][0][0]  [p] [0][0]
			%*.*i	,3,2,1	-> ' 01'	[**][0][0]  [**][0][0]  [wp][0][0]
			%3.*i	,2,1	-> ' 01'	[*] [3][0]  [ *][3][0]  [p] [3][0]
			%*.2i	,3,1	-> ' 01'	[*] [0][2]  [* ][0][2]  [w] [0][2]
			%3.2i	,1		-> ' 01'	[]  [3][2]  [  ][3][2]  []  [3][2]
		if lst->next->a_nb == lst->a_nb rerun for next list element but same argument
		{{str; flag; width; precision; length; specifier; arg; p_nb 2; a_nb 1},
		 {str; flag; width; precision; length; specifier; arg; p_nb 1; a_nb 2},
		 {str; flag; width; precision; length; specifier; arg; p_nb 3; a_nb 3},
		 {str; flag; width; precision; length; specifier; arg; p_nb 5; a_nb 3},
		 {str; flag; width; precision; length; specifier; arg; p_nb 4; a_nb 4}}
		 
		conversions : cspdiuxX%
		      flags : -,0,.,*
		conversions : nfge
		      flags : l,ll,h,hh,#,', ,+
	
		usage :
		printf		%[arg_nbr$][flags #,0,-, ,+,'][width *][.precision *][length hh,h,ll,l,L,j,t,z][specifier d,i,u,x,X,c,s,p,%,e,f,g,n,E,F,G,a,A,C,S,o]
		ft_printf	%          [flags 0,-        ][width *][.precision *]                          [specifier d,i,u,x,X,c,s,p,%                        ]
		bonus		%          [flags     #,', ,+]                       [length hh,h,ll,l        ][specifier                   e,f,g,n                ]
	
		[arg_nbr]
	(	nbr$	specify the argument to access, they are numbered starting at 1
	
		[flags] #,0,-, ,+,'
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
				
	
		[specifiers] d,i,u,x,X,c,s,p,%,e,f,g,n,E,F,G,a,A,C,S,o
		c	char	character
		s	*char	string of characters
		p	*		pointer adress
		d	int		(or i) signed decimal integer
		i	int		(or d) signed decimal integer
		u	int		unsigned decimal integer
		x	int		unsigned hexadecimal integer
		X	int		unsigned hexadecimal integer (capital letters)
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
*/
