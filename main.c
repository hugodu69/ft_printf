#include "ft_printf.h"
#include <stdio.h> // for printf
#include <locale.h>
#include <fcntl.h> // for dup() and dup2()


// macro to print :
// first the string,
// then the result of real printf,
// then the result of ft_printf,
// and finally redirect the output into a file to compare
#define PRINT(string, args...)		\
									outf = open("outf.txt", O_WRONLY | O_TRUNC); \
									outft = open("outft.txt", O_WRONLY | O_TRUNC); \
									\
									dup2(outf, 1); \
									printf(string "\n", ##args); \
									fflush(stdout); \
									\
									dup2(outft, 1); \
									if ((ft_printf(string, ##args)) == -1) printf("\033[91mERROR\033[0m"); \
									fflush(stdout); \
									printf("\n"); \
									fflush(stdout); \
									\
									close(outf); \
									close(outft); \
									outf = open("outf.txt", O_RDONLY); \
									outft = open("outft.txt", O_RDONLY); \
									\
									dup2(save, 1); \
									printf("(%s, %s)", #string, #args); \
									fflush(stdout); \
									printf("%*s", (int)(40 - ft_strlen(#string) - ft_strlen(#args)), ": "); \
									fflush(stdout); \
									printf("'" string "'\n", ##args); \
									fflush(stdout); \
									printf("%s", ft_compare(outf, outft, &error)); \
									fflush(stdout); \
									printf("%38s", ": '"); \
									fflush(stdout); \
									if ((ft_printf(string, ##args)) == -1) printf("\033[91mERROR\033[0m"); \
									fflush(stdout); \
									printf("'\n\n"); \
									fflush(stdout); \
									\
									close(outf); \
									close(outft);

/*
** this fucntion look into the two files outf.txt and outft.txt in which
** the return values of printf and ft_printf are saved for one call
** (the content is emptied each time there are reopened by the macro)
** and it read them and compare them
*/

char	*ft_compare(int fd1, int fd2, int *error)
{
	int		ret1 = 1;
	int		ret2 = 1;
	char	*line = NULL;
	char	*tmp = NULL;

	while (ret1 > 0 && ret2 > 0)
	{
		ret1 = get_next_line(fd1, &line);
		tmp = line;
		ret2 = get_next_line(fd2, &line);
  		if (ft_strcmp(tmp, line) != 0)
  		{
			free(line);
			free(tmp);
  			(*error)++;
  			return ("\033[91mHO HO..\033[0m");
  		}
		free(line);
		free(tmp);
	}
	if (ret1 != ret2)
	{
		(*error)++;
		return ("\033[91mHO HO..\033[0m");
	}
	return ("JACKPOT");
}

/*
** this function was usefull at the very beginning to understand how va_arg
** works, it's an extension of the exemple code found in the man page
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

/*
** this is the main function of tests, with a loooooot of tests, enjoy ;)
** if you call the executable without arguments, it will print the usage
** otherwise you can add one of three keywords :
** "man" for the very beginner tests
** "test" for the debug tests while building the programm
** "all" for the huge amount of possibly complete tests
*/

int		main(int ac, char **av)
{
	setlocale(LC_ALL, "en_US.UTF-8");

	int	outf;
	int	outft;
	open("outf.txt", O_CREAT, 0644);
	open("outft.txt", O_CREAT, 0644);
	static int error = 0;
	int	save = dup(1);


	/* ////////////////////////////////////////////////////////////////// */
	/* PREMISES TESTS WITH AV_ARG BASED ON MAN EXEMPLE                    */
	/* ////////////////////////////////////////////////////////////////// */

	if (ac == 1)
	{
		printf("USAGE:\n");
		printf("call ./ft_printf with arguments to launch tests :\n");
		printf("./ft_printf  'man'                \n");
		printf("...........  'test'               \n");
		printf("...........  'special'            \n");
		printf("...........  'all'                \n");
		printf("...........   ...     'noflag'    \n");
		printf("...........   ...     '0'         \n");
		printf("...........   ...     '-'         \n");
		printf("...........   ...     'width'     \n");
		printf("...........   ...     'precision' \n");
		printf("...........   ...     '*'         \n");
		printf("...........   ...     'd'         \n");
		printf("...........   ...     'i'         \n");
		printf("...........   ...     'u'         \n");
		printf("...........   ...     'x'         \n");
		printf("...........   ...     'X'         \n");
		printf("...........   ...     'c'         \n");
		printf("...........   ...     's'         \n");
		printf("...........   ...     'p'         \n");
		printf("...........   ...     '%%'        \n");
		printf("...........   ...     'repetition'\n");
		printf("...........  'bonus'              \n");
		printf("...........   .....   '#'         \n");
		printf("...........   .....   '''         \n");
		printf("...........   .....   ' '         \n");
		printf("...........   .....   '+'         \n");
		printf("...........   .....   'e'         \n");
		printf("...........   .....   'f'         \n");
		printf("...........   .....   'g'         \n");
		printf("...........   .....   'n'         \n");
		printf("...........   .....   'h'         \n");
		printf("...........   .....   'hh'        \n");
		printf("...........   .....   'l'         \n");
		printf("...........   .....   'll'        \n");
		printf("...........   .....   'repetition'\n");
		printf("...........  'error'              \n");
	}

	if (ac == 2 && !strcmp(av[1], "man"))
	{
		char			*str = "diuxXcsefg";
		int				d = 123;
		int				i = 456;
		unsigned int	u = 345;
		unsigned int	x = 456;
		unsigned int	X = 567;
		char			c = 'c';
		char*			s = "string";
		//				p = ;
		float			e = 678;
		float			f = 789;
		float			g = 890;
		//				n = ;
		char				*str2 = "iiIIuU";
		int					i1 = 2147483647;
		int					i2 = -2147483648;
		long int			i3 = 9223372036854775807;
		long int			i4 = -9223372036854775807;
		unsigned int		i5 = 4294967295;
		//long unsigned int	i6 = 18446744073709551615;
		long unsigned int	i6 = 8446744073709551615;
	
		// test one of each specifiers
		printf("%s : %d : %i : %u : %x : %X : %c : %s : %e : %f : %g\n", str, d, i, u, x, X, c, s, e, f, g);
		ft_printf_test(str, d, i, u, x, X, c, s, e, f, g);
		// test all different size of int types
		printf("%s : %i : %i : %li : %li : %u : %lu\n", str2, i1, i2, i3, i4, i5, i6);
		ft_printf_test(str2, i1, i2, i3, i4, i5, i6);
	}

	/* ////////////////////////////////////////////////////////////////// */
	/* TESTS WHILE BUILDING THE PROGRAM                                   */
	/* ////////////////////////////////////////////////////////////////// */

	if (ac == 2 && !strcmp(av[1], "test"))
	{
		PRINT("sdf");
		PRINT("%i", 23);
		long int k = -23;
		PRINT("%li", k);
		PRINT("%i", -32);
		PRINT("%li", 9223372036854775807);
		PRINT("%c", 'f');
		PRINT("%s", "sdffhk");
		PRINT("%u", 1221879);
		PRINT("%x", 3287);
		PRINT("%lX", 9223372036854775807);
  		PRINT("%p", "dfgdf");
		PRINT("%.i", 121);
		PRINT("%.2i", 122);
		PRINT("%.25i", 123);
		PRINT("%0.6i", 124);
		//PRINT("%-032.6i", 125);			// '0' and '-' not compatible
		//PRINT("%0-032.6i", 126);			// '0' and '-' not compatible
		//PRINT("%0-0.6i", 127);			// '0' and '-' not compatible
		PRINT("%s", "string");
		PRINT("%.7s", "strong");
		PRINT("%.2s", "strung");
		PRINT("%.0s", "strang");
		PRINT("%.s", "streng");
		PRINT("%.7i", -123456);
		PRINT("%2i", -128);
		PRINT("%0i", -129);
		PRINT("%10i", -130);
		PRINT("%*i", 0,-131);
		//PRINT("%0s", "stryng");			// '0' not compatible with string
		PRINT("%10s", "strxng");
		//PRINT("%010s", "strzng");			// '0' not compatible with string
		PRINT("%s" "__TEST__", "strzng");
		char *s = "hess";
		PRINT("%s", s)
	}

	/* ////////////////////////////////////////////////////////////////// */
	/* TESTS FROM THE PRINT UNIT TEST                                     */
	/* ////////////////////////////////////////////////////////////////// */

	if (ac == 2 && !strcmp(av[1], "special"))
	{
		PRINT("%16c", (char)0)
		PRINT("%-16c", (char)0)
		PRINT("%16c", 'a')
		PRINT("%-16c", 'a')
		PRINT("%16c", (char)7)
		PRINT("!%37c!", (char)0)
	}

	/* ////////////////////////////////////////////////////////////////// */
	/* COMPLETE TESTS SERIES                                              */
	/* ////////////////////////////////////////////////////////////////// */

	if (ac >= 2 && ac <= 3 && !strcmp(av[1], "all"))
	{
		if (ac == 2 || !strcmp(av[2], "noflag"))
		{
			printf("\n----------------------------------------------------------------\n");
			printf("conversions sans flags : cspdiuxX%%\n");
			printf("----------------------------------------------------------------\n\n");

			char *str = "bravo";
			PRINT("%%");
			PRINT("%.10%");
			PRINT("%10%");
			PRINT("%-10%");
			PRINT("%010%");
			PRINT("%-010%");
			PRINT("\"");
			PRINT("%c", 'c');
			PRINT("%s", "str");
			PRINT("%s", str);
			PRINT("%p", "bravo");
			PRINT("%p", str);
			PRINT("%d", 456);
			PRINT("%i", 846);
			PRINT("%u", 87);
			PRINT("%u", -87);
			PRINT("%x", 124);
			PRINT("%X", 124);
			PRINT("%X", 123456);
			PRINT("%X", 0x1E240);
			PRINT("%i", 0x1E240);
		}

		if (ac == 2 || !strcmp(av[2], "0"))
		{
			printf("----------------------------------------------------------------\n");
			printf("flag '0' (diouxX%%)\n");
			printf("----------------------------------------------------------------\n\n");

			PRINT("%03i", 1);
			PRINT("%03u", 1);
			PRINT("%03x", 1);
			PRINT("%03%");
			PRINT("%0%");
		}

		if (ac == 2 || !strcmp(av[2], "-"))
		{
			printf("\n----------------------------------------------------------------\n");
			printf("flag '-'\n");
			printf("----------------------------------------------------------------\n\n");

			PRINT("%-3s", "a");
			PRINT("%-9s", "a");
			PRINT("%-1s", "ab");
			PRINT("%-2s", "ab");
			PRINT("%-3s", "ab");
			PRINT("%-3i", 3);
			PRINT("%-3i", 123456);
		}

		if (ac == 2 || !strcmp(av[2], "width"))
		{
			printf("\n----------------------------------------------------------------\n");
			printf("taille de champ minimale\n");
			printf("----------------------------------------------------------------\n\n");

			PRINT("%3s", "a");
			PRINT("%3s", "abcd");
			PRINT("%3i", 12);
			PRINT("%2i", 12);
			PRINT("%1i", 12);
			PRINT("%0i", 0);
			PRINT("%6i", -456);
			PRINT("%6%");
			PRINT("%16c", 'a');
			PRINT("%16c", (char)97);
		}

		if (ac == 2 || !strcmp(av[2], "precision"))
		{
			printf("\n----------------------------------------------------------------\n");
			printf("flag '.precision' (diouxXs)\n");
			printf("----------------------------------------------------------------\n");

			printf("-if the . is not followed by a number, the value is 0\n");
			printf("-with arg value of 0, precision of 0 print nothing\n");
			printf("-with numbers (diouxX), gives the minimum number of digit to appear\n");
			printf(" if precision > nbr, it's preceded by '0'\n");
			printf(" if nbr < 0, '-' is not counted in precision\n");
			printf(" (length with '-' is (length(nbr or precision) + 1)'\n");
			printf(" if 0 flag is given (for width or precision) it's ignored\n");
			printf("-with strings (s), gives the maximum number of characters to be print\n");
			printf(" if precision > length(s), it's not preceded by '0'\n");
			printf("-precision is calculated before width\n");
			printf("----------------------------------------------------------------\n\n");
	
			PRINT("%.5s", "12");
			PRINT("%.5s", "12345678");
			PRINT("%12.5s", "12345678");
			PRINT("%.5i", 12);
			PRINT("%.7X", 8645);
			PRINT("%7.7X", 8645);
			PRINT("%9.7X", 8645);
			PRINT("%-9.7X", 8645);
			PRINT("%7.9X", 8645);
			PRINT("%.0i", 0);
			PRINT("%.0i", 000);
			PRINT("%.0X", 0);
			PRINT("%.i", 0);
			PRINT("%i", 0);
			PRINT("%010.7X", 8645);
			PRINT("%10.7X", 8645);
			PRINT("%-10.7X", 8645);
			PRINT("%-.7i", 8645);
			PRINT("%.7i", -8645);
			PRINT("%.07i", 8645);
			PRINT("%.7%");
		}

		if (ac == 2 || !strcmp(av[2], "*"))
		{
			printf("\n----------------------------------------------------------------\n");
			printf("flag '*' with .precision or width\n");
			printf("----------------------------------------------------------------\n\n");

			PRINT("%*i", 3, 1);
			PRINT("%-*i", 3, 1);
			PRINT("%*i-%*i", 1, 2, 3, 4);
			PRINT("%*i-%*i", 0, 1, 2, 3);
			PRINT("%.*i-%.*i", 0, 1, 2, 3);
			PRINT("%3.2i", 1);
			PRINT("%*.*i", 3, 2, 1);
		}

		if (ac == 2 || !strcmp(av[2], "d"))
		{
			printf("\n----------------------------------------------------------------\n");
			printf("specifier 'd'\n");
			printf("----------------------------------------------------------------\n\n");
		}

		if (ac == 2 || !strcmp(av[2], "i"))
		{
			printf("\n----------------------------------------------------------------\n");
			printf("specifier 'i'\n");
			printf("----------------------------------------------------------------\n\n");
		}

		if (ac == 2 || !strcmp(av[2], "u"))
		{
			printf("\n----------------------------------------------------------------\n");
			printf("specifier 'u'\n");
			printf("----------------------------------------------------------------\n\n");
		}

		if (ac == 2 || !strcmp(av[2], "x"))
		{
			printf("\n----------------------------------------------------------------\n");
			printf("specifier 'x'\n");
			printf("----------------------------------------------------------------\n\n");
		}

		if (ac == 2 || !strcmp(av[2], "X"))
		{
			printf("\n----------------------------------------------------------------\n");
			printf("specifier 'X'\n");
			printf("----------------------------------------------------------------\n\n");
		}

		if (ac == 2 || !strcmp(av[2], "c"))
		{
			printf("\n----------------------------------------------------------------\n");
			printf("specifier 'c'\n");
			printf("----------------------------------------------------------------\n\n");
		}

		if (ac == 2 || !strcmp(av[2], "s"))
		{
			printf("\n----------------------------------------------------------------\n");
			printf("specifier 's'\n");
			printf("----------------------------------------------------------------\n\n");
		}

		if (ac == 2 || !strcmp(av[2], "p"))
		{
			printf("\n----------------------------------------------------------------\n");
			printf("specifier 'p'\n");
			printf("----------------------------------------------------------------\n\n");

			char *s;
			PRINT("%p", "test")
			PRINT("%p", s)
			s = "truc";
			PRINT("%p", s)
			unsigned int u = 4;
			PRINT("%p", &u)
			PRINT("%s-%p", s, s)
			PRINT("%u-%p", u, &u)
			PRINT("%up", u)
		}

		if (ac == 2 || !strcmp(av[2], "%"))
		{
			printf("\n----------------------------------------------------------------\n");
			printf("specifier '%%'\n");
			printf("----------------------------------------------------------------\n\n");
		}

		if (ac == 2 || !strcmp(av[2], "repetition"))
		{
			printf("\n----------------------------------------------------------------\n");
			printf("tests repetitions of flags [0-]\n");
			printf("----------------------------------------------------------------\n\n");

			PRINT("%i", 33333);
			PRINT("%08i", 33333);
			PRINT("%-8i", 33333);

			printf("\nrepetition of flag '0' -----------------------------------------\n");
			printf("'0' and '-' not compatible -------------------------------------\n\n");

			PRINT("%0000i", 33333);

			printf("\nrepetition of flag '-' -----------------------------------------\n");
			printf("'0' and '-' not compatible -------------------------------------\n\n");

			PRINT("%----i", 33333);
		}
	}
	
	if (ac >= 2 && ac <= 3 && !strcmp(av[1], "bonus"))
	{
		printf("----------------------------------------------------------------\n");
		printf("%% flags   width   .precision  length      specifier            \n");
		printf("%% 0-#' +  * 0..9  .* 0..9     hhhlllLjtz  diuxXcsp%%efgnEFGaACSo\n");
		printf("%% 0-      * 0..9  .* 0..9                 diuxXcsp%%            \n");
		printf("%%   #' +                      hhhlll               efgn        \n");
		printf("----------------------------------------------------------------\n\n");

		if (ac == 2 || !strcmp(av[2], "#"))
		{
			printf("\n----------------------------------------------------------------\n");
			printf("flag '#'\n");
			printf("----------------------------------------------------------------\n\n");
	
			PRINT("%#X", 8645);
			PRINT("%#.7X", 8645);
			PRINT("%#010.7X", 8645);
			PRINT("%#10.7X", 8645);
			PRINT("%#10X", 8645);
			PRINT("%#.10X", 8645);
			PRINT("%#10.10X", 8645);
			PRINT("%#010X", 8645);
			unsigned int uu = 4;
			PRINT("%#X", (unsigned int)&uu)
			PRINT("%#x", (unsigned int)&uu)
			PRINT("%#lx", (unsigned long int)&uu)
		}

		if (ac == 2 || !strcmp(av[2], "'"))
		{
			printf("\n----------------------------------------------------------------\n");
			printf("flag '''\n");
			printf("----------------------------------------------------------------\n\n");
		}

		if (ac == 2 || !strcmp(av[2], " "))
		{
			printf("\n----------------------------------------------------------------\n");
			printf("flag ' '\n");
			printf("----------------------------------------------------------------\n\n");
		}

		if (ac == 2 || !strcmp(av[2], "+"))
		{
			printf("\n----------------------------------------------------------------\n");
			printf("flag '+'\n");
			printf("----------------------------------------------------------------\n\n");
		}

		if (ac == 2 || !strcmp(av[2], "e"))
		{
			printf("\n----------------------------------------------------------------\n");
			printf("specifier 'e'\n");
			printf("----------------------------------------------------------------\n\n");
		}

		if (ac == 2 || !strcmp(av[2], "f"))
		{
			printf("\n----------------------------------------------------------------\n");
			printf("specifier 'f'\n");
			printf("----------------------------------------------------------------\n\n");
		}

		if (ac == 2 || !strcmp(av[2], "g"))
		{
			printf("\n----------------------------------------------------------------\n");
			printf("specifier 'g'\n");
			printf("----------------------------------------------------------------\n\n");
		}

		if (ac == 2 || !strcmp(av[2], "n"))
		{
			printf("\n----------------------------------------------------------------\n");
			printf("specifier 'n'\n");
			printf("----------------------------------------------------------------\n\n");
		}

		if (ac == 2 || !strcmp(av[2], "h"))
		{
			printf("\n----------------------------------------------------------------\n");
			printf("length 'h'\n");
			printf("----------------------------------------------------------------\n\n");
		}

		if (ac == 2 || !strcmp(av[2], "hh"))
		{
			printf("\n----------------------------------------------------------------\n");
			printf("length 'hh'\n");
			printf("----------------------------------------------------------------\n\n");
		}

		if (ac == 2 || !strcmp(av[2], "l"))
		{
			printf("\n----------------------------------------------------------------\n");
			printf("length 'l'\n");
			printf("----------------------------------------------------------------\n\n");
		}

		if (ac == 2 || !strcmp(av[2], "ll"))
		{
			printf("\n----------------------------------------------------------------\n");
			printf("length 'll'\n");
			printf("----------------------------------------------------------------\n\n");
		}

		if (ac == 2 || !strcmp(av[2], "repetition"))
		{
			printf("\n----------------------------------------------------------------\n");
			printf("tests repetitions of flags [0-#' +]\n");
			printf("----------------------------------------------------------------\n\n");

			PRINT("%i", 33333);
			PRINT("%.0f", 33333.0);
			PRINT("%#.0f", 33333.0);
			PRINT("%08i", 33333);
			PRINT("%-8i", 33333);
			PRINT("%+i", 33333);
			PRINT("% i", 33333);
			PRINT("%'i", 33333);

			printf("\nrepetition of flag '0' -----------------------------------------\n");
			printf("'0' and '-' not compatible -------------------------------------\n\n");

			PRINT("%0000i", 33333);
			PRINT("%0#.0f", 33333.0);
			PRINT("%#0.0f", 33333.0);
			PRINT("%0#0.0f", 33333.0);
			PRINT("%0+8i", 33333);
			PRINT("%+08i", 33333);
			PRINT("%0+08i", 33333);
			PRINT("%0 i", 33333);
			PRINT("% 0i", 33333);
			PRINT("%0 0i", 33333);
			PRINT("%0'i", 33333);
			PRINT("%'0i", 33333);
			PRINT("%0'0i", 33333);

			printf("\nrepetition of flag '-' -----------------------------------------\n");
			printf("'0' and '-' not compatible -------------------------------------\n\n");

			PRINT("%----i", 33333);
			PRINT("%-#.0f", 33333.0);
			PRINT("%#-.0f", 33333.0);
			PRINT("%-#-.0f", 33333.0);
			PRINT("%-+8i", 33333);
			PRINT("%+-8i", 33333);
			PRINT("%-+-8i", 33333);
			PRINT("%- i", 33333);
			PRINT("% -i", 33333);
			PRINT("%- -i", 33333);
			PRINT("%-'i", 33333);
			PRINT("%'-i", 33333);
			PRINT("%-'-i", 33333);

			printf("\nrepetition of flag '#' -----------------------------------------\n");

			PRINT("%####f", 33333.0);
			PRINT("%#+.0f", 33333.0);
			PRINT("%+#.0f", 33333.0);
			PRINT("%#+#.0f", 33333.0);
			PRINT("%#08f", 33333.0);
			PRINT("%0#8f", 33333.0);
			PRINT("%#0#8f", 33333.0);
			PRINT("%#-8f", 33333.0);
			PRINT("%-#8f", 33333.0);
			PRINT("%#-#8f", 33333.0);
			PRINT("%#'f", 33333.0);
			PRINT("%'#f", 33333.0);
			PRINT("%#'#f", 33333.0);
			PRINT("%# f", 33333.0);
			PRINT("% #f", 33333.0);
			PRINT("%# #f", 33333.0);

			printf("\nrepetition of flag ''' -----------------------------------------\n\n");

			PRINT("%''''i", 33333);
			PRINT("%'#.0f", 33333.0);
			PRINT("%#'.0f", 33333.0);
			PRINT("%'#'.0f", 33333.0);
			PRINT("%'08i", 33333);
			PRINT("%0'8i", 33333);
			PRINT("%'0'8i", 33333);
			PRINT("%'-8i", 33333);
			PRINT("%-'8i", 33333);
			PRINT("%'-'8i", 33333);
			PRINT("%'+i", 33333);
			PRINT("%+'i", 33333);
			PRINT("%'+'i", 33333);
			PRINT("%' i", 33333);
			PRINT("% 'i", 33333);
			PRINT("%' 'i", 33333);

			printf("\nrepetition of flag ' ' -----------------------------------------\n");
			printf("'+' and ' ' not compatible -------------------------------------\n\n");

			PRINT("%    i", 33333);
			PRINT("% #.0f", 33333.0);
			PRINT("%# .0f", 33333.0);
			PRINT("% # .0f", 33333.0);
			PRINT("% 08i", 33333);
			PRINT("%0 8i", 33333);
			PRINT("% 0 8i", 33333);
			PRINT("% -8i", 33333);
			PRINT("%- 8i", 33333);
			PRINT("% - 8i", 33333);
			PRINT("% 'i", 33333);
			PRINT("%' i", 33333);
			PRINT("% ' i", 33333);

			printf("\nrepetition of flag '+' -----------------------------------------\n");
			printf("'+' and ' ' not compatible -------------------------------------\n\n");

			PRINT("%++++i", 33333);
			PRINT("%+#.0f", 33333.0);
			PRINT("%#+.0f", 33333.0);
			PRINT("%+#+.0f", 33333.0);
			PRINT("%+08i", 33333);
			PRINT("%0+8i", 33333);
			PRINT("%+0+8i", 33333);
			PRINT("%+-8i", 33333);
			PRINT("%-+8i", 33333);
			PRINT("%+-+8i", 33333);
			PRINT("%+'i", 33333);
			PRINT("%'+i", 33333);
			PRINT("%+'+i", 33333);
		}
	}

	if (ac == 2 && !strcmp(av[1], "error"))
	{
			printf("-----------------------------------------------\n");
			printf("- errors                                      -\n");
			printf("-----------------------------------------------\n\n");
	
			printf("(\"%%i\",3,2)           : ");	ft_printf("'%i'", 3, 2);		printf(" too much argments\n\n");
			printf("(\"%%i-%%i\",3)         : ");	ft_printf("'%i-%i'", 3);		printf(" not enough arguments\n\n");
	  		printf("(\"%%-03i\",1)          : ");	ft_printf("'%-03i'", 1);		printf(" flag 0 is ignored when - is present\n\n");
			printf("(\"%%010s\",\"str\")    : ");	ft_printf("'%010s'", "str");	printf(" flag 0 has undefined behavior with s specifier\n\n");
			printf("(\"%%010c\",'c')        : ");	ft_printf("'%010c'", 'c');		printf(" flag 0 has undefined behavior with c specifier\n\n");
			printf("(\"%%03p\",\"str\")     : ");	ft_printf("'%03p'\n", "str");	printf(" flag 0 has undefined behavior with p specifier\n\n");
			printf("(\"%%.-7X\",8645)       : ");	ft_printf("'%.-7X'", 8645);		printf(" invalid flag - for .precision\n\n");
			printf("(\"%%\",8645)           : ");	ft_printf("'%'", 8645);			printf(" missing conversion specifier\n\n");
			printf("(\"%%2$i-%%i\",3,2)     : ");	ft_printf("'%2$i-%i'", 3, 2);	printf(" cannot mix positioned and non-positioned args\n\n");
			printf("(\"%% +i\", 33          : ");	ft_printf("'% +i'\n", 33);		printf(" flag ' ' is ignored when '+' is present\n\n");
			printf("(\"%%-0i\", 33          : ");	ft_printf("'%-0i'\n", 33);		printf(" flag '0' is ignored when '-' is present\n\n");
	}

	printf("\n----------------------------------------------------------------\n");
	printf("%% flags   width   .precision  length      specifier            \n");
	printf("%% 0-#' +  * 0..9  .* 0..9     hhhlllLjtz  diuxXcsp%%efgnEFGaACSo\n");
	printf("%% 0-      * 0..9  .* 0..9                 diuxXcsp%%            \n");
	printf("%%   #' +                      hhhlll               efgn        \n");
	printf("----------------------------------------------------------------\n\n");

	close(save);
	if (error != 0)
		printf("\033[91m%i ERRORS\033[0m\n", error);
	return (0);
}

/*
**	conversions : cspdiuxX%
**	      flags : - 0 . *
**	conversions : nfge
**	      flags : l ll h hh # ' (space) +
**	
**	%[arg_nbr$][flags 0,-,#,', ,+][width *][.precision *][length hh,h,ll,l,L,j,t,z][specifier d,i,u,x,X,c,s,p,%,e,f,g,n,E,F,G,a,A,C,S,o]
**	%          [flags 0,-        ][width *][.precision *]                          [specifier d,i,u,x,X,c,s,p,%                        ]
**	%          [flags     #,', ,+]                       [length hh,h,ll,l        ][specifier                   e,f,g,n                ]
**	
**	
**			[flags]
**			-		left-justify within the given field width
**			0		left-pads the number with zeroes (0) instead of spaces, where
**					padding is specified (see width sub-specifier)
**		(	+		forces to precede the result with a plus or minus sign even for
**					positive numbers)
**		(	(space)	if no sign is going to be written, a blank space is inserted
**					before the value)
**		(	#		(o, x, X, a, A, e, E, f, F, g, G) used with (o, x or X) the
**					value is preceded with 0, 0x or 0X for values different than
**					zero. used with (e, E or f), it forces the written output to
**					contain a decimal point even if no digits would follow. by
**					default, if no digits follow, no decimal point is written. used
**					with (g or G) the result is the same as with e or E but trailing
**					zeros are not removed
**		(	'		(d, u, i, f, F) used with d, u or i, or the integral portion of
**					a float f or F, the decimal conversions are printed by groups of
**					thousands separated by the non-monetary separator returned by
**					localeconv(3) (ex 123456789 -> 123,456,789)
**					
**			[width]
**			(nbr)	minimum number of characters to be printed. if the value to be
**					printed is shorter than this number, the result is padded with
**					blank spaces. The value is not truncated even if the result is
**					larger
**			*		the width is not specified in the format string, but as an
**					additional integer value argument preceding the argument that
**					has to be formatted
**		
**			[.precision]
**			.nbr	fot integer specifiers (d,i,o,x,X) - precision specifies the
**					minimum number of digits to be written. If the value to be
**					written is shorter than this number, the result is padded with
**					leading zeros. The value is not truncated even if the result is
**					longer. A precision of 0 means that no character is written for
**					the value 0. For e, E and f specifiers − this is the number of
**					digits to be printed after the decimal point. For g and G
**					specifiers − This is the maximum number of significant digits
**					to be printed. For s − this is the maximum number of characters
**					to be printed. By default all characters are printed until the
**					ending null character is encountered. For c type − it has no
**					effect. When no precision is specified, the default is 1. If the
**					period is specified without an explicit value for precision, 0
**					is assumed
**			.*		the precision is not specified in the format string, but as an
**					additional integer value argument preceding the argument that
**					has to be formated
**	
**			[specifiers]
**			c	char	character
**			s	*char	string of characters
**			p	*		pointer adress
**			d	int		(or i) signed decimal integer
**			i	int		(or d) signed decimal integer
**			u	u int	unsigned decimal integer
**			x	u int	unsigned hexadecimal integer
**			X	u int	unsigned hexadecimal integer (capital letters)
**		(	n	*int	nothing printed
**		(	f	float	decimal floating point
**		(	e	float	scientific notation (mantissa/exponent) using e
**		(	g	float	uses the shorter of %e or %f
**		((F	float
**		((E	float	scientific notation (mantissa/exponent) using E
**		((G	float	uses the shorter of %E or %f
**		((o	int		signed octal
**		((C	char	treated as c with l modifier
**		((a	float
**		((A	float
**		((S	*char	treated as s with l modifier
**		
**	
**	p == long unsigned int
**	
**	char		1bytes	8bits
**	short		2bytes	16bits
**	int			4bytes	32bits
**	long		8bytes	64bits
**	long long	8bytes	64bits
**	
**	                 255                  -127 - +127                   00 [char]				[hhd, hhi, c]			[int]			[d( , h, hh), i( , h, hh), c]
**	               65535                -32768 - +32767                 01 [short]				[hd, hi]				[int]
**	          4294967295           -2147483648 - +2147483647            02 [int]				[d, i]					[int]
**	18446744073709551615  -9223372036854775808 - +9223372036854775807   04 [long]				[ld, li]				[long]			[d(l ,ll), i(l, ll)]
**	18446744073709551615  -9223372036854775808 - +9223372036854775807   04 [long long]			[lld, lli]				[long]
**	                 256                     0 - +255                   05 [unsigned char]		[hhu, hhx, hhX]			[unsigned int]	[u( , h, hh), x( , h, hh), X( , h, hh), p]
**	               65536                     0 - +65536                 06 [unsigned short]		[hu, hx, hX]			[unsigned int]
**	          4294967296                     0 - +4294967296            07 [unsigned int]		[u, x, X, p]			[unsigned int]
**	18446744073709551616                     0 - +18446744073709551616  09 [unsigned long]		[lu, lx, lX]			[unsigned long]	[s, u(l, ll), x(l, ll), X(l, ll)]
**	18446744073709551616                     0 - +18446744073709551616  09 [unsigned long long]	[llu, llx, llX]			[unsigned long]
**	18446744073709551616                     0 - +18446744073709551616  10 [char *]				[s, hhn]				[unsigned long]
**	
**	18446744073709551616                     0 - +18446744073709551616  16 [double]				[e, le, f, lf, g, lg]	[]
**	18446744073709551616                     0 - +18446744073709551616  17 [wint_t]				[lc]					[]
**	18446744073709551616                     0 - +18446744073709551616  18 [wchar_t]			[ls]					[]
**	18446744073709551616                     0 - +18446744073709551616  11 [short *]			[hn]					[]
**	18446744073709551616                     0 - +18446744073709551616  12 [int *]				[n]						[]
**	18446744073709551616                     0 - +18446744073709551616  13 [long *]				[ln]					[]
**	18446744073709551616                     0 - +18446744073709551616  14 [long long *]		[lln]					[]
**	
**	d	int						0	int
**	dhh	char					1	char
**	dh	short					2	short
**	dl	long					3	long
**	dll	long long				4	long long
**	
**	i	int
**	ihh	char
**	ih	short
**	il	long
**	ill	long long
**	
**	u	unsigned int			5	unsigned int
**	uhh	unsigned char			6	unsigned char
**	uh	unsigned short			7	unsigned short
**	ul	unsigned long			8	unsigned long
**	ull	unsigned long long		9	unsigned long long
**	
**	x	unsigned int
**	xhh	unsigned char
**	xh	unsigned short
**	xl	unsigned long
**	xll	unsigned long long
**	
**	X	unsigned int
**	Xhh	unsigned char
**	Xh	unsigned short
**	Xl	unsigned long
**	Xll	unsigned long long
**	
**	c	char -> int
**	cl	wint_t					10	wint_t
**	s	char *					11	char *
**	sl	wchar_t *				12	wchar_t *
**	p	unsigned int
**	e	double					13	double
**	el	
**	f	double
**	fl	
**	g	double
**	gl	
**	
**	n	int *					14	int *
**	nhh	char *
**	nh	short *					15	short *
**	nl	long *					16	long *
**	nll	long long *				17	long long *
**	
**		printf("char               %lu\n", sizeof(char));
**		printf("short              %lu\n", sizeof(short));
**		printf("int                %lu\n", sizeof(int));
**		printf("long               %lu\n", sizeof(long));
**		printf("long long          %lu\n", sizeof(long long));
**		printf("unsigned char      %lu\n", sizeof(unsigned char));
**		printf("unsigned short     %lu\n", sizeof(unsigned short));
**		printf("unsigned int       %lu\n", sizeof(unsigned int));
**		printf("unsigned long      %lu\n", sizeof(unsigned long));
**		printf("unsigned long long %lu\n", sizeof(unsigned long long));
**		printf("char *             %lu\n", sizeof(char *));
**		printf("short *            %lu\n", sizeof(short *));
**		printf("int *              %lu\n", sizeof(int *));
**		printf("long *             %lu\n", sizeof(long *));
**		printf("long long *        %lu\n", sizeof(long long *));
**		printf("double             %lu\n", sizeof(double));
**	//	printf("wint_t             %lu\n", sizeof(wint_t));
**	//	printf("wchar_T            %lu\n", sizeof(wchar_t));
**
**		int flag:                  pw+ '#-0
**		00000000 00000000 00000000 00000001 == 1	'0'
**		00000000 00000000 00000000 00000010 == 2	'-'
**		00000000 00000000 00000000 00000100 == 4	'#'
**		00000000 00000000 00000000 00001000 == 8	'''
**		00000000 00000000 00000000 00010000 == 16	' '
**		00000000 00000000 00000000 00100000 == 32	'+'
**		00000000 00000000 00000000 01000000 == 64	'*' width
**		00000000 00000000 00000000 10000000 == 128	'*' precision
**
**		typedef struct		s_prist
**		{
**			char			*str;
**			int				flag;		// default 0    ; [0-#' +**] binary
**			int				width;		// default 0    ;
**			int				prec;		// default 0    ; precision
**			char			*length;	// default "\0" ;
**			char 			spec;		// default 0    ; specifier
**			char			*arg;		// default "\0" ;
**			int				p_nb;		// default 0    ; print_nb : order in which to print (order it was found in string)
**			int				a_nb;		// default 0    ;   arg_nb : number of the corresponding argument (for flag $)
**			struct s_prist	*next;
**		}					t_prist;
**
**		("2 1 3 4 3", 1, 2, 3, 4)
**
**		ft_error(int err)
**		ft_store("%i truc %-10d machin\n")
**			ft_split_print(str)
**				prist->str = "%i";
**					ft_fill_lst(prist)
**						prist->flag;		// default = 0
**						prist->width;		// default = 0
**						prist->prec;		// default = 0
**						prist->length;
**						prist->spec;
**						prist->p_nb;
**						prist->a_nb;		// if not $ == p_nb
**				prist->str = " truc ";
**					ft_fill_lst(prist)
**						...					// if str start without % it means it can be printed as a string directly
**				prist->str = "%-10d";
**					ft_fill_lst...
**				prist->str = " machin\n";
**					ft_fill_lst...
**			return
**			{{str; flag; width; precision; length; specifier; p_nb 1; a_nb 2},
**			 {str; flag; width; precision; length; specifier; p_nb 2; a_nb 1},
**			 {str; flag; width; precision; length; specifier; p_nb 3; a_nb 3},
**			 {str; flag; width; precision; length; specifier; p_nb 4; a_nb 4},
**			 {str; flag; width; precision; length; specifier; p_nb 5; a_nb 3}}
**
**		ft_sort_by_arg
**		{{str; flag; width; precision; length; specifier; p_nb 2; a_nb 1},
**		 {str; flag; width; precision; length; specifier; p_nb 1; a_nb 2},
**		 {str; flag; width; precision; length; specifier; p_nb 3; a_nb 3},
**		 {str; flag; width; precision; length; specifier; p_nb 5; a_nb 3},
**		 {str; flag; width; precision; length; specifier; p_nb 4; a_nb 4}}
**
**		ft_add_arg
**		if lst->str[o] != '\%'  rerun without looking for argument
**		if lst->flag == *  rerun for next argument but same list element
**										[fl][w][p]  or          or
**			%i		,1		-> '1'		[]  [0][0]  [  ][0][0]  []  [0][0]
**			%*i		,3,1	-> '  1'	[*] [0][0]  [* ][0][0]  [w] [0][0]
**			%.*i	,2,1	-> '01'		[*] [0][0]  [ *][0][0]  [p] [0][0]
**			%*.*i	,3,2,1	-> ' 01'	[**][0][0]  [**][0][0]  [wp][0][0]
**			%3.*i	,2,1	-> ' 01'	[*] [3][0]  [ *][3][0]  [p] [3][0]
**			%*.2i	,3,1	-> ' 01'	[*] [0][2]  [* ][0][2]  [w] [0][2]
**			%3.2i	,1		-> ' 01'	[]  [3][2]  [  ][3][2]  []  [3][2]
**		if lst->next->a_nb == lst->a_nb rerun for next list element but same argument
**		{{str; flag; width; precision; length; specifier; arg; p_nb 2; a_nb 1},
**		 {str; flag; width; precision; length; specifier; arg; p_nb 1; a_nb 2},
**		 {str; flag; width; precision; length; specifier; arg; p_nb 3; a_nb 3},
**		 {str; flag; width; precision; length; specifier; arg; p_nb 5; a_nb 3},
**		 {str; flag; width; precision; length; specifier; arg; p_nb 4; a_nb 4}}
*/
