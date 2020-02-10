# - - - - - - - - - #
#  variables names  #
# - - - - - - - - - #

NAME   = ft_printf
CC     = gcc
VPATH  = srcs

IDIR   = .
_DEPS  = ft_printf.h
DEPS   = $(_DEPS:%.h=$(IDIR)/%.h)

LDIR   = ./libft.c/
_LIBS  = libft.a
LIBS   = $(_LIBS:lib%.a=%)

SRCS   = ft_printf.c \
         ft_next_word.c

ODIR   = ./builds
OBJS   = $(SRCS:%.c=$(ODIR)/%.o)

CFLAGS = -I$(IDIR)
LFLAGS = -L$(LDIR) -l$(LIBS)

# - - - - - - - - - - - #
#   rules to execute    #
# - - - - - - - - - - - #

all: $(ODIR) $(NAME)
$(NAME): $(OBJS) $(DEPS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LFLAGS)
$(ODIR):
	mkdir -p $@
$(ODIR)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
clean:
	/bin/rm -rf $(ODIR)
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all
lib:
	make fclean -C $(LDIR)
	make -C $(LDIR)
.PHONY: all clean fclean re lib
