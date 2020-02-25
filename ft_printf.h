#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"

# include <stdio.h>

// ft_printf.c
char	*ft_flag_transform(char *s, char *print, char *type);
int		ft_printf(char *string, ...);

// ft_next_word.c
int		width_precision(char *s);
int		word_length(char *s);
char	*next_word(char **s);

// aside.c
char	*specifier(char *s);
int		ft_put_word(char *s);
int		ft_expand_star(int nbr, char **string);

// ft_convert.c
char	*conv_i(char c, long int i);
char	*conv_u(char c, unsigned long int i);
char	*ft_convert(va_list ap, char *type);

// ft_width_n_precision.c
char	*precision_int(char *print, int precision);
char	*ft_precision(char *s, char *print, char *type);
char	*width_flags(char *print, char *tmp, char *s, int width);
char	*ft_width(char *s, char *print);

#endif
