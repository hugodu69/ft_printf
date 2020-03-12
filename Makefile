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
		 ft_flag_transform_bonus.c \
		 main.c

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
	/bin/rm -rf $(ODIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

# - - - - - - - - - - - #
#    rules to test      #
#         with          #
#    main and libft     #
# - - - - - - - - - - - #

lib:
	make -C $(LDIR)
cleanlib: lib
	make fclean -C $(LDIR)
main: $(ODIR) $(OBJS) $(DEPS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS)
fsanitize: $(ODIR) $(OBJS) $(DEPS)
	$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -fsanitize=address
gcc:
	$(CC) $(CFLAGS) main.c -L. -lftprintf
mainfclean: fclean
	/bin/rm -f out*.txt a.out

.PHONY: all clean fclean re lib cleanlib main fsanitize mainfclean gcc
