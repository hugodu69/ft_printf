#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(char *string, ...);

typedef struct		s_prist
{
	char			*str;
	int				flag;
	int				width;
	int				prec;
	char			*length;
	char 			spec;
	char			*arg;
	int				p_nb;
	int				a_nb;
	struct s_prist	*next;
}					t_prist;

#endif
