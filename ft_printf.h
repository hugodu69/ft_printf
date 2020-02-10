#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft.c/libft.h"

# include <libc.h>

int		ft_printf(char *string, ...);

int		width_precision(char *s);
int		word_length(char *s);
char	*next_word(char **s);

#endif
