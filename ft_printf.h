#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

# include <stdio.h>

int		ft_printf(char *string, ...);

int		width_precision(char *s);
int		word_length(char *s);
char	*next_word(char **s);
char	*ft_convert(va_list ap, char *type);
char	*specifier(char *s);
int		ft_put_word(char *s);
int		ft_expand_star(int nbr, char **string);

#endif
