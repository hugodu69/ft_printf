
#include "ft_printf.h"

int		ft_error(int i)
{
	if (i == 0)
		return (1);
	return (0);
}


/*
%[arg_nbr$][flags 0,-,#,', ,+][width *][.precision *][length hh,h,ll,l,L,j,t,z][specifier d,i,u,x,X,c,s,p,%,e,f,g,n,E,F,G,a,A,C,S,o]
%          [flags 0,-        ][width *][.precision *]                          [specifier d,i,u,x,X,c,s,p,%                        ]
%          [flags     #,', ,+]                       [length hh,h,ll,l        ][specifier                   e,f,g,n                ]

str = "%3s - truc: %.2i - machin: %04c \n"

ft_next_word
	if str[0] == '%'
		from str+1 to [specifier];
	else
		from str[0] to '%';
	[%3s][ - truc: ][%.2i][ - machin: ][%04c][ \n]

while ((s = next_word(str)) != NULL)
	type = ft_specifier(&s);				// return the type according to specifier and length && pull them out of s
	while (flag_*(s))
		s = ft_expand_star(va_arg, "i", s);	// (use ft_convert) replace first * by arg in s, ex: "%*.*i" --> "%2.*i" --> "%2.3i"
	print = ft_convert(va_arg, type);
	if ((i = flag_p(s)))
		print = ft_precision(i, print);
	if ((i = flag_w(s)))
		if (flag_-(s))
			print = ft_right_padded(i, print);
		else if (flag_0(s))
			print = ft_right_padded(i, print);
(	if (flag_+(s))
(	else if (flag_space(s))
(	if (flag_'(s))
(	if (flag_#(s))
(		print = ft_alternate_form(print)
			

*/
char		*ft_nextword(char *str)
{
	char	*word;

	word = strdup(str);
	return (word);
}

t_prist		*ft_store(char *str)
{
	t_prist	*lst;
	t_prist	*lstmp;
	char	*tmp;

	lst = NULL;
	while (*str != '\0')
	{
		lstmp = lst;
		(*lst) = (t_prist *)malloc(sizeof(*lst));
		tmp = ft_nextword(str);
		(*arglst)->str = ft_strdup(tmp);
		...fill_flag...;
		if (tmp != NULL)
			tmp[0] = '%';
			str = tmp;
		lst->next = lstmp;
	}
	return (lst);
}

int		ft_printf(char *string, ...)
{
	t_prist	*lst;
	va_list	ap;

	va_start(ap, string);
	lst = ft_store(string);
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
*/
