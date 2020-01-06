#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(char *string, ...);

typedef struct		s_prist
{
	int				print_nbr;
	int				arg_nbr;
	int				flag;
	int				width;
	int				precision;
	char			*length;
	char 			specifier;
	char			*arg;
	struct s_prist	*next;
}					t_prist;

#endif
