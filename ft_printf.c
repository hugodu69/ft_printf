
//#include "ft_printf.h"
#include <libc.h>

typedef unsigned char *ta_list;
#define ta_start(list, param) (list = (((ta_list)&param) + sizeof(param)))
#define ta_arg(list, type)    (*(type *)((list += sizeof(type)) - sizeof(type)))

//int		ft_printf(char *string, ...)
int		ft_printf(int num, ...)
{
//	ta_list	ap;
	char	*arg;
//	int		d;
//	char	c;
//	char	*s;

	arg = (char *)&num;
	arg++;
	printf("%s\n", arg);
/*	while (*arg != '\0')
		arg++;
	arg += 1;
	//arg = (((char*)&string) + sizeof(string));
	//ta_start(ap, string);
	while (*string != '\0')
	{
		if (*string == 's')
		{
			//s = ta_arg(ap, char *);
			s = (char *)arg;
			printf("string '%s'\n", s);
		//	while (*arg != '\0')
		//	{
			//	printf(" '%1$i%1$c' ", *arg);
		//		arg++;
		//	}
		//	printf(" '%1$i%1$c' ", *arg);
			arg += sizeof(char *);
		//	printf(" '%1$i%1$c' \n", *arg);
			//arg += sizeof(char *);
		}
		if (*string == 'd')
		{
			//d = ta_arg(ap, int);
			d = (int)(*arg);
			printf("int %d\n", d);
		}
		if (*string == 'c')
		{
			//c = ta_arg(ap, int);
			//c = (char)(*arg);
			printf("char %s\n", arg);
		}
		string++;
	}*/

//	va_list	ap;
//
//	va_start(ap, string);
//	while (*string != '\0')
//	{
//		if (*string == 's')
//		{
//			s = va_arg(ap, char *);
//			printf("string %s\n", s);
//		}
//		if (*string == 'd')
//		{
//			d = va_arg(ap, int);
//			printf("int %d\n", d);
//		}
//		if (*string == 'c')
//		{
//			c = va_arg(ap, int);
//			printf("char %c\n", c);
//		}
//		string++;
//	}
//	va_end(ap);
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
	ft_printf(4, s, c, str, i);
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

typedef struct		s_prist
{
	int				print_nbr;
	int				arg_nbr;
	int				flag;	//[0-#' +*] binary
	int				width;
	int				precision;
	char			*length;
	char 			specifier;
	char			*arg;
	struct s_prist	*next;
}					t_prist;

("2 1 3 4 3", 1, 2, 3, 4)

ft_store
for each : ft_check_error
{{printf_nbr 1; arg_nbr 2; flag; width; precision; length; specifier},
 {printf_nbr 2; arg_nbr 1; flag; width; precision; length; specifier},
 {printf_nbr 3; arg_nbr 3; flag; width; precision; length; specifier},
 {printf_nbr 4; arg_nbr 4; flag; width; precision; length; specifier},
 {printf_nbr 5; arg_nbr 3; flag; width; precision; length; specifier}}

ft_sort_by_arg
{{printf_nbr 2; arg_nbr 1; flag; width; precision; length; specifier},
 {printf_nbr 1; arg_nbr 2; flag; width; precision; length; specifier},
 {printf_nbr 3; arg_nbr 3; flag; width; precision; length; specifier},
 {printf_nbr 5; arg_nbr 3; flag; width; precision; length; specifier},
 {printf_nbr 4; arg_nbr 4; flag; width; precision; length; specifier}}

ft_add_arg
if flag == * >> rerun for next argument but same list element
if lst->next->arg == lst->arg rerun for next list element but same argument
{{printf_nbr 2; arg_nbr 1; flag; width; precision; length; specifier; arg},
 {printf_nbr 1; arg_nbr 2; flag; width; precision; length; specifier; arg},
 {printf_nbr 3; arg_nbr 3; flag; width; precision; length; specifier; arg},
 {printf_nbr 5; arg_nbr 3; flag; width; precision; length; specifier; arg},
 {printf_nbr 4; arg_nbr 4; flag; width; precision; length; specifier; arg}}

*/
