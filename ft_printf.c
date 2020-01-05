#include "ft_printf.h"

	//	%[arg_nbr$][flags][][width][.precision][length]specifier

int		ft_printf(char *fmt, ...)
{
	va_list	ap;
	int		d;
	char	c, *s;

	va_start(ap, fmt);
	while (*fmt != '\0')
	{
		if (*fmt == 's')
		{
			s = va_arg(ap, char *);
			printf("string %s\n", s);
		}
		if (*fmt == 'd')
		{
			d = va_arg(ap, int);
			printf("int %d\n", d);
		}
		if (*fmt == 'c')
		{
			c = va_arg(ap, int);
			printf("char %c\n", c);
		}
		fmt++;
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
	return (0);
}

/*

conversions : cspdiuxX%
      flags : -,0,.,*
conversions : nfge
      flags : l,ll,h,hh,#,', ,+

%[arg_nbr$][flags 0,-,#,', ,+][width *][.precision *][length hh,h,ll,l,L,j,t,z][specifier d,i,u,x,X,c,s,p,%,e,f,g,n,E,F,G,a,A,C,S,o]
%          [flags 0,-        ][width *][.precision *]                          [specifier d,i,u,x,X,c,s,p,%                        ]
%          [flags     #,', ,+]                       [length hh,h,ll,l        ][specifier                   e,f,g,n                ]

typedef struct		s_prist
{
	int				print_nbr;
	int				arg_nbr;
	char 			specifier;
	int				flag;	//['0','-','#',''',' ','+','*'] binary
	int				width;
	int				precision;
	char			*arg;
	struct s_prist	*next;
}					t_prist;

("2 1 3 4 3", 1, 2, 3, 4)

store
{{printf_nbr 1; arg_nbr 2; specifier; flag; width; precision},
 {printf_nbr 2; arg_nbr 1; specifier; flag; width; precision},
 {printf_nbr 3; arg_nbr 3; specifier; flag; width; precision},
 {printf_nbr 4; arg_nbr 4; specifier; flag; width; precision},
 {printf_nbr 5; arg_nbr 3; specifier; flag; width; precision}}

check_more_error

sort_by_arg
{{printf_nbr 2; arg_nbr 1; specifier; flag; width; precision},
 {printf_nbr 1; arg_nbr 2; specifier; flag; width; precision},
 {printf_nbr 3; arg_nbr 3; specifier; flag; width; precision},
 {printf_nbr 5; arg_nbr 3; specifier; flag; width; precision},
 {printf_nbr 4; arg_nbr 4; specifier; flag; width; precision}}

add_str_to_print
if flag == * >> rerun for next argument but same list element
{{printf_nbr 2; arg_nbr 1; specifier; flag; width; precision; arg},
 {printf_nbr 1; arg_nbr 2; specifier; flag; width; precision; arg},
 {printf_nbr 3; arg_nbr 3; specifier; flag; width; precision; arg},
 {printf_nbr 5; arg_nbr 3; specifier; flag; width; precision; arg},
 {printf_nbr 4; arg_nbr 4; specifier; flag; width; precision; arg}}

*/
