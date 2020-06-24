# - - - - - - - - - #
#  variables names  #
# - - - - - - - - - #

NAME   = libftprintf.a
CC     = gcc
VPATH  = srcs

IDIR   = .
_DEPS  = ft_printf.h
DEPS   = $(_DEPS:%.h=$(IDIR)/%.h)

LDIR   = ./libft/
_LIBS  = libft.a
LIBS   = $(_LIBS:lib%.a=%)

SRCS   = ft_printf.c \
         ft_next_word.c \
		 ft_convert.c \
		 ft_flag_transform.c \
		 ft_flag_transform_bonus.c

ODIR   = ./builds
OBJS   = $(SRCS:%.c=$(ODIR)/%.o)

CFLAGS = -I$(IDIR) -g
LFLAGS = -L$(LDIR) -l$(LIBS)

# - - - - - - - - - - - #
#   rules to execute    #
# - - - - - - - - - - - #

all: $(NAME)

$(NAME): $(ODIR) $(OBJS) $(DEPS)
	make -C $(LDIR)
	cp $(LDIR)$(_LIBS) ./
	mv $(_LIBS) $(NAME)
	ar -rc $@ $(OBJS)
	ranlib $@

$(ODIR):
	mkdir -p $@

$(ODIR)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	make clean -C $(LDIR)
	/bin/rm -rf $(ODIR)

fclean: clean
	make fclean -C $(LDIR)
	/bin/rm -f $(NAME)
	/bin/rm -rf out*.txt a.out a.out.dSYM temoin.txt exemple.txt

re: fclean all

gcc:
	$(CC) $(CFLAGS) main.c -L. -lftprintf

.PHONY: all clean fclean re gcc
