# - - - - - - - - - #
#  variables names  #
# - - - - - - - - - #

NAME	=	libft.a
CC		=	gcc
VPATH	=	srcs/

IDIR	=	./includes
_DEP	=	libft.h
DEPS	=	$(_DEP:%.h=$(IDIR)/%.h)

CFLAGS	=	-I$(IDIR)
CFLAGS +=	-Wall -Wextra -Werror

SRCS	=	ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strchrset.c \
			ft_strncmp.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			\
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_utoa.c \
			ft_strmapi.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			\
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			\
			ft_strcat.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strncat.c \
			ft_strncpy.c \
			ft_strstr.c \
			ft_strjoinfree.c \
			ft_strclr.c \
			ft_strdel.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_putchar.c \
			ft_putendl.c \
			ft_putnbr.c \
			ft_putnbrendl.c \
			ft_putnbrendl_fd.c \
			ft_putnbrbase.c \
			ft_putstr.c \
			ft_any.c \
			ft_atoibase.c \
			ft_convertbase.c \
			ft_convertbase_free.c \
			ft_foreach.c \
			ft_issort.c \
			ft_arraymap.c \
			ft_strmultisplit.c \
			\
			get_next_line.c \
			ft_concat_free.c

ODIR	=	./builds
OBJS	=	$(SRCS:%.c=$(ODIR)/%.o)


# - - - - - - - - - - - #
#   rules to execute    #
# - - - - - - - - - - - #


all: $(NAME)

$(ODIR):
	@printf "\033[35m"
	mkdir -p $(ODIR)
	@printf "\033[0m"

$(NAME): $(ODIR) $(OBJS) $(DEPS)
	@printf "\033[33m"
	ar -rc $@ $(OBJS)
	ranlib $@
	@printf "\033[0m"

$(ODIR)/%.o: %.c
	@printf "\033[36m"
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@printf "\033[31m"
	/bin/rm -rf $(ODIR)
	@printf "\033[0m"

fclean: clean
	@printf "\033[31m"
	/bin/rm -f $(NAME)
	@printf "\033[0m"

re: fclean all

.PHONY: clean fclean re all











# ------------------------------------------------------ #
# explication complete etapes par etapes depuis le debut #
# ------------------------------------------------------ #

## 1 - compiler avec gcc						   [25 gj]
# compiler un programme							   [29 gj]
# compiler en plusieurs fichiers				   [54 gj]
# les .o : compiler et linker					  [102 gj]

## 2 - creer une librairie						  [135 gj]
# ar rc											  [139 gj]
# ar rc en plusieurs fois						  [164 gj]
# ranlib										  [185 gj]

## 3 - fichiers .h								  [198 gj]
# a quoi sert un header							  [202 gj]
# ecrire un header								  [229 gj]
# comment ca se compile							  [273 gj]

## 4 - ecrire un make file						  [305 gj]
# basic makefile								  [309 gj]
# makefile with subdirectories					  [462 gj]
# makefile making another makefile				  [583 gj]
# makefile for a library						  [690 gj]

## ----------------------
## 1 - compiler avec gcc
## ----------------------

# - - - - - - - - - - - - - - - - - - - - - -
# compiler un programme qui contient un main
# - - - - - - - - - - - - - - - - - - - - - -

# quand on ecrit un programme il contient un main et les
# fonctions dont le main a besoin (ex ft_putchar) :
#
#	# #include <unistd.h>
#	#
#	# void	ft_putchar(char c)
#	# {
#	#	write(1, &c, 1);
#	# }
#	#
#	# int	main()
#	# {
#	#	ft_putchar('0');
#	#	return (0);
#	# }
#
# on peut compiler ce fichier avec gcc en faisant :
# gcc file.c
# et ca sort un executable a.out
# si on l'execute "./a.out" ca ecrit 0 dans la console

# - - - - - - - - - - - - - - - - - - - - - - -
# compiler un programme en plusieurs fichiers
# - - - - - - - - - - - - - - - - - - - - - - -

# on va vite vouloir mettre chaque fonctions utilisee
# dans un fichier a part afin de mieux gerer les modules
# d'un programme. donc si on sort ft_putchar du fichier :
#
#	# int	main()
#	# {
#	#	ft_putchar('0');
#	#	return (0);
#	# }
#
# et qu'on execute "gcc file.c" on va avoir une erreur
# car file.c utilise ft_putchar mais gcc ne sait pas ce
# que c'est, donc il faut faire deux choses :
#
# 1 - d'une part indiquer a main() que ft_putchar()
# existe, en ecrivant au dessus non pas toute la fonction
# (puisqu'on veut la mettre dans un fichier a part) mais
# uniquement son prototype :
#
#	# void	ft_putchar(char c);
#
# 2 - et d'autre part qu'on rajoute le fichier contenant
# la fonction ft_putchar a la compilation :
#
#	[ft_putchar.c]
#	# #include <unistd.h>
#	#
#	# void	ft_putchar(char c)
#	# {
#	#	write(1, &c, 1);
#	# }
#
#	[main.c]
#	# void	ft_putchar(char c);
#	#
#	# int	main()
#	# {
#	#	ft_putchar('0');
#	#	return (0);
#	# }
#
# si on compile les deux ca marche :
# gcc main.c ft_putchar.c

# - - - - - - - - - - - - - - -
# les .o : compiler et linker
# - - - - - - - - - - - - - - -

# ca fonctionne mais gcc doit a chaque fois recompiler
# ft_putchar.c alors qu'il n'est pas modifie, donc on peut
# le compiler une bonne fois pour toute et l'ajouter a la
# compilation finale quand on en a besoin sans que l'ordi
# ait a tout retraduire dans son langage
#
# mais si on essaye de compiler ft_putchar seul
#
#	# gcc ft_putchar.c
#
# ca nous donne une erreur car pour compiler, gcc a besoin
# de trouver un main !
#
# on va donc utiliser l'option -c pour creer un fichier
# objet .o qui est deja traduit en langue d'ordinateur
# et pret a etre rajoute a la compilation :
#
#	# gcc -c ft_putchar.c	--> donne ft_putchar.o
#	# gcc -c main.c			--> donne main.o
#
# cette etape qui consiste a transformer les fichiers en
# objets .o s'appelle la compilation, il faut ensuite
# linker les objets, ce qui avec gcc se fait simplement :
#
#	# gcc main.o ft_putchar.o
#
# on va maintenant voir comment faire une libraire qui
# contient tous nos fichiers objets

## ------------------------
## 2 - creer une librairie
## ------------------------

# - - - -
# ar rc
# - - - -

# pour mettre tous les fichiers .o dans un seul fichier .a
# on utilise un programme d'archive ar avec les options rc
# - r indique d'inserer les .o en remplacant si necessaire
# - c de creer une nouvelle archive
#
# le nom de l'archive doit commencer par lib et
# finir par .a :
#
#	# ar rc libtest.a ft_putchar.o
#
# on obtient un fichier libtest.a qui contient les
# fichiers objets .o
#
# on peut l'utiliser a la compilation de cette manniere :
#
#	# gcc main.c -L. -ltest
#
# -L indique ou est la librairie (ici elle est dans le
# dossier courant .)
# -l indique son nom (TEST car on n'indique pas lib et .a)

# - - - - - - - - - - - - -
# ar rc en plusieurs fois
# - - - - - - - - - - - - -

# on n'est pas oblige de creer une librairie en une seule
# fois, ce qui est bien pratique nottament pour les
# makefiles, on verra ca apres.
#
# ca signifie que si notre librairie contient plusieurs
# fonctions, par exmple la librairie libfruits.a contient
# banane.o et orange.o, on peut creer la librairie
# avec banane.o puis y ajouter orange.o, sans auncune
# manipulation speciale :
#
#	# ar rc libfruits.a banane.o
#	# ar rc libfruits.a orange.o
#
# revient au meme qu'ecrire :
#
#	# ar rc libfruits.a banane.o orange.o

# - - - -
# ranlib
# - - - -

# ranlib creer un index du contenu de la librairie et le
# place dedans, c'est utile des que la librairie est tres
# grande afin que gcc sache acceder rapidement aux
# fonctions dont il a besoin dedans
#
#	# ranlib libtest.a
#
# ranlib s'utilise apres avoir creer la lib avec ar rc

## ----------------
## 3 - fichiers .h
## ----------------

# - - - - - - - - - - - -
# a quoi sert un header
# - - - - - - - - - - - -
# si on utilise une librairie c'est parce qu'on peut avoir
# souvent besoin des memes fonctions dans un programme
# mais si a chaque fois qu'on utilise une fonction de la
# librairie on doit ecrire son prototype, ca va poser deux
# problemes :
#
# le prototype d'une seule fonction peut etre ecrit a
# pleins d'endroits, donc si la fonction change un peu on
# doit retrouver tous les emplacements des prototypes et
# les modifier un par un
#
# et d'autre part, si on utilise pleins de fonctions dans
# l'ecriture d'un programme on va devoir reecrire a chaque
# fois son prototype et c'est tres relou
#
# afin d'eviter ca on ecrit tous les prototypes, ainsi que
# les includes, et les structures, les defines, et autres,
# dans un seul fichier pour tout un programme, ou dans le
# cas present pour toute la librairie, et on l'inclus
# systematiquement au debut d'un fichier contenant des
# fonctions de la librairie, gcc s'occupera de l'expandre
# a la precompilation
#

# - - - - - - - - -
# ecrire un header
# - - - - - - - - -

#	[ft_putchar.c]
#	# #include "libtest.h"
#	#
#	# void	ft_putchar(char c)
#	# {
#	#	write(1, &c, 1);
#	# }
#
#	[main.c]
#	# #include "libtest.h"
#	#
#	# int	main()
#	# {
#	#	ft_putchar('0');
#	#	return (0);
#	# }
#
#	[libetest.h]
#	# # ifndef LIBTEST_H
#	# # define LIBTEST_H
#	# 
#	# #include <unistd.h>
#	# 
#	# void	ft_putchar(char c);
#	# 
#	# # endif
#
# en tete de chaque fichier de fonctions on ecrit
# l'include de la librairie, comme un include classique,
# precede d'un #, mais avec le nom de la librairie entre
# guillemets et non pas entre signes comparateurs
#
# dans le fichier de la librairie on ajoute les includes
# dont on peut avoir besoin pour que la librairie ou des
# fonctions auont besoin, et les prototypes des fonctions
#
# on entoure toutes ces infos par une definition, afin
# de proteger le .h d'etre expand plusieurs fois dans
# un fichier

# - - - - - - - - - - - -
# comment ca se compile
# - - - - - - - - - - - -

# au moment de la compilation il faut indiquer a gcc ou
# se trouve le fichier .h avec le flag -I
#
# par exemple pour l'architecture de dossier suivante :
#
#	# file/
#	#    main.c
#	#    ft_putchar.c
#	#    libtest.h
#
# il faut ecrire :
#
#	# gcc main.c ft_putchar.c -I.
#
# et si la compilation utilise une librairie, par exemple
# si on met la fonction ft_putchar.c dans une librairie :
#
#	# gcc -c ft_putchar.c
#	# (donne ft_putchar.o)
#	# ar rc libtest.a ft_putchar.o
#
# on peut alors compiler avec la librairie .a et le
# fichier .h :
#
#	# gcc main.c -I. -L. -ltest -o test
#
# qui sort l'executable "test"

## ----------------------------------------------------
## 4 - ecrire un make file pour aider a la compilation
## ----------------------------------------------------

# - - - - - - - - -
# makefile basique
# - - - - - - - - -

# exemple for a basic makefile :
#
#	[architecture]
#	# main.c
#	# function01.c
#	# function02.c
#	# header.h
#	# libtest.a
#	# Makefile
#
#	[Makefile]
#	# #-------------#
#	# #  VARIABLES  #
#	# #-------------#
#	# NAME   = program_test
#	# CC     = gcc
#	# CFLAGS = -I.
#	# LFLAGS = -L. -ltest
#	# DEPS   = header.h
#	# SRCS   = main.c \
#	#          function01.c \
#	#          function02.c
#	# ODIR   = ./builds
#	# OBJS   = $(SRCS:%.c=%.o)
#	# 
#	# #---------#
#	# #  RULES  #
#	# #---------#
#	# all: $(ODIR) $(NAME)
#	# $(NAME): $(OBJS) $(DEPS)
#	#     $(CC) $(CFLAGS) -o $@ $(OBJS) $(LFLAGS)
#	# %.o: %.c
#	#     $(CC) $(CFLAGS) -c -o $@ $<
#	# clean:
#	#     /bin/rm -rf $(ODIR)
#	# fclean: clean
#	#     /bin/rm -f $(NAME)
#	# re: fclean all
#	# .PHONY: all clean fclean re
#
#	# prompt "make" execute the first rule ("all")
#
#	[architecture]
#	# main.c
#	# main.o
#	# function01.c
#	# function01.o	++
#	# function02.c
#	# function02.o	++
#	# header.h
#	# libtest.a
#	# Makefile
#	# program_test	++
#
# -----
#
# shape of a rule :
#
# target: prerequisites ...
#		recipe ...
#
# when a target is called, its execution depends of the
# prerequisites, if they have been more recently modify
# than the target the makefile execute the recipe
#
# to execute a rull you have to call it's name with make :
# "make rule", and by default the first rule is execute
#
# -----
#
# "automatic variables"
#
# $@ is the name of the target that called the rule
# $< is the name of the first prerequisite
# $^ is the name of all the prerequisites
#
# -----
#
# $(SRCS:%.c=%.o)
#
# is a built-in function called a "substitute reference",
# an abbreviation for the expansion function "patsubst" :
#
# $(patsubst pattern,replacement,text)
# $(text:pattern=replacement)
#
# $() is a variable which expand in its value
#
# % match everything, the value of the first % in
# "replacement" is replaced with the text matched by the
# first % in "pattern", it only works for the firsts
#
# -----
#
# all: $(ODIR) $(NAME)
#
# ALL depends on ODIR and NAME, so if ODIR doesn't exist
# it will be created, and then NAME is called
#
# -----
#
# $(NAME): $(OBJS) $(DEPS)
# 		$(CC) $(CFLAGS) -o $@ $(OBJS) $(LFLAGS)
#
# NAME depends on OBJS and DEPS, so if any .o or any .h
# have more recent date of modification NAME will execute
# only for them
#
# -----
#
# %.o: %.c
# 	$(CC) $(CFLAGS) -c -o $@ $<
#
# when $(OBJS) expand in the list of .o files at the call
# of the NAME rule, each of them call the rule "%.o" wich
# depends on the equivalent .c, so if one has been
# modified since last execution of ALL, it's recompiled in
# object file with use of automatic variables $@ and $<
#
# -----
#
# #clean:
#		/bin/rm -rf $(ODIR)
#
# "make clean" suppress all the .o files
#
# -----
#
# fclean: clean
#		/bin/rm -f $(NAME)
#
# "make fclean" call CLEAN and suppress the executable
#
# -----
#
# re: fclean all
#
# "make fclean" basically rerun make
#
# -----
#
# .PHONY: all clean fclean re
#
# a phony target is one that is not the name of a file
# if a file called "clean" for instance exist, the rule
# CLEAN will never be executed when prompt "make clean"
# because it will be considered up to date, but if it's
# declared to be phony it will be executed in any case

# - - - - - - - - - - - - - - -
# makefile with subdirectories
# - - - - - - - - - - - - - - -

# put the .o in a "builds/" directory
#
# have the .c in a "srcs/" directory
#
# have the .h in an "includes" directory
#
# have multiples .a files
#
#	[architecture]
#	# srcs/
#	#    main.c
#	#    function01.c
#	#    function02.c
#	# includes/
#	#    header01.h
#	#    header02.h
#	# libtest.a
#	# liboption.a
#	# Makefile
#
#	# #-------------#
#	# #  VARIABLES  #
#	# #-------------#
#	# NAME   = program_test
#	# CC     = gcc
#	# VPATH  = srcs
#	#
#	# IDIR   = includes
#	# _DEPS  = header01.h \
#	#          header02.h
#	# DEPS   = $(_DEPS:%.h=$(IDIR)/%.h)
#	#
#	# LDIR   = ./
#	# _LIBS  = libtest.a \
#	#          liboption.a
#	# LIBS   = $(_LIBS:lib%.a=%)
#	#
#	# SRCS   = main.c \
#	#          function01.c
#	#          function02.c
#	# ODIR   = ./builds
#	# OBJS   = $(SRCS:%.c=$(ODIR)/%.o)
#	#
#	# CFLAGS = -I$(IDIR)
#	# LFLAGS = -L$(LDIR) -l$(LIBS)
#	# 
#	# #---------#
#	# #  RULES  #
#	# #---------#
#	# all: $(ODIR) $(NAME)
#	# $(NAME): $(OBJS) $(DEPS)
#	#     $(CC) $(CFLAGS) -o $@ $(OBJS) $(LFLAGS)
#	# $(ODIR):
#	#     mkdir -p $@
#	# $(ODIR)/%.o: %.c
#	#     $(CC) $(CFLAGS) -c -o $@ $<
#	# clean:
#	#     /bin/rm -rf $(ODIR)
#	# fclean: clean
#	#     /bin/rm -f $(NAME)
#	# re: fclean all
#	# .PHONY: all clean fclean re
#
#	# prompt "make" execute the first rule ("all")
#
#	[architecture]
#	# srcs/
#	#    main.c
#	#    function01.c
#	#    function02.c
#	# includes/
#	#    header01.h
#	#    header02.h
#	# builds/			++
#	#    main.o			++
#	#    function01.o	++
#	#    function02.o	++
#	# libtest.a
#	# liboption.a
#	# Makefile
#	# program_test		++
#
# -----
#
# VPATH  = srcs
#
# build-in variable VPATH is a list of directories where
# makefile looks for files that it doesn't find in the
# first place, so it let you easily put .c files into
# subdirectories
#
# -----
#
# LIBS   = $(_LIBS:lib%.a=%)
#
# from "libtest.a" and "liboption.a" it creates "test"
# and "option"
#
# as said, the value of the % in "replacement" is
# replaced with the text matched by the % in "pattern"
#
# -----
#
# OBJS   = $(SRCS:%.c=$(ODIR)/%.o)
#
# creates the list of .o from the .c with addition of the
# path directory "builds/main.o"
#
# it could be :
# $(patsubst %.c,$(ODIR)/%.o,$(SRCS))
# or :
# $(addprefix $(ODIR)/, $(SRCS:.c=.o))
#
# -----
#
# $(NAME): $(OBJS) $(DEPS)
# 		$(CC) $(CFLAGS) -o $@ $(OBJS) $(LFLAGS)
#
# NAME depends on OBJS and DEPS, so if any .o or any .h
# have more recent date of modification NAME will execute
# again only for them

# - - - - - - - - - - - - - - - - -
# makefile making another makefile
# - - - - - - - - - - - - - - - - -

# compiling a makefile with compiling another makefile in
# a subdirectory wich contain the library used by the
# roots makefile
#
#	[architecture]
#	# srcs/
#	#    main.c
#	#    function01.c
#	#    function02.c
#	# includes/
#	#    header01.h
#	#    header02.h
#	# libtest/
#	#    Makefile
#	#    header_lib.h
#	#    function_lib01.c
#	#    function_lib02.c
#	#    libtest.a
#	# Makefile
#
#	# #-------------#
#	# #  VARIABLES  #
#	# #-------------#
#	# NAME   = program_test
#	# CC     = gcc
#	# VPATH  = srcs
#	#
#	# IDIR   = includes
#	# _DEPS  = header01.h \
#	#          header02.h
#	# DEPS   = $(_DEPS:%.h=$(IDIR)/%.h)
#	#
#	# LDIR   = ./libtest/
#	# _LIBS  = libtest.a \
#	# LIBS   = $(_LIBS:lib%.a=%)
#	#
#	# SRCS   = main.c \
#	#          function01.c
#	#          function02.c
#	# ODIR   = ./builds
#	# OBJS   = $(SRCS:%.c=$(ODIR)/%.o)
#	#
#	# CFLAGS = -I$(IDIR)
#	# LFLAGS = -L$(LDIR) -l$(LIBS)
#	# 
#	# #---------#
#	# #  RULES  #
#	# #---------#
#	# all: $(ODIR) $(NAME)
#	# $(NAME): $(OBJS) $(DEPS)
#	#     make -C $(LDIR)
#	#     $(CC) $(CFLAGS) -o $@ $(OBJS) $(LFLAGS)
#	# $(ODIR):
#	#     mkdir -p $@
#	# $(ODIR)/%.o: %.c
#	#     $(CC) $(CFLAGS) -c -o $@ $<
#	# clean:
#	#     make clean -C $(LDIR)
#	#     /bin/rm -rf $(ODIR)
#	# fclean: clean
#	#     make fclean -C $(LDIR)
#	#     /bin/rm -f $(NAME)
#	# re: fclean all
#	# .PHONY: all clean fclean re
#
#	# prompt "make" execute the first rule ("all")
#
#	[archtecture]
#	# srcs/
#	#    main.c
#	#    function01.c
#	#    function02.c
#	# includes/
#	#    header01.h
#	#    header02.h
#	# builds/				++
#	#    main.o				++
#	#    function01.o		++
#	#    function02.o		++
#	# libtest/
#	#    Makefile
#	#    header_lib.h
#	#    function_lib01.c
#	#    function_lib02.c
#	#    libtest.a
#	# Makefile
#	# program_test			++
#
# -----
#
# make -C $(LDIR)
#
# make -C <path>
#
# the -C option says to makefile it should first go to the
# path location and then do "make"
#
# it's similar to :
#
# rule:
#     cd $(LDIR) && make
#

# - - - - - - - - - - - -
# makefile for a library
# - - - - - - - - - - - -

#
# exemple of a makefile used not for a compilation into a
# binary executable, but to create a library
#
#	[architecture]
#	# srcs/
#	#    function01.c
#	#    function02.c
#	# includes/
#	#    header.h
#	# Makefile
#
#	# #-------------#
#	# #  VARIABLES  #
#	# #-------------#
#	# NAME   = libtest.a
#	# CC     = gcc
#	# VPATH  = srcs
#	#
#	# IDIR   = includes
#	# _DEPS  = header.h
#	# DEPS   = $(_DEPS:%.h=$(IDIR)/%.h)
#	#
#	# SRCS   = function01.c \
#	#          function02.c
#	# ODIR   = ./builds
#	# OBJS   = $(SRCS:%.c=$(ODIR)/%.o)
#	#
#	# CFLAGS = -I$(IDIR)
#	# 
#	# #---------#
#	# #  RULES  #
#	# #---------#
#	# all: $(ODIR) $(NAME)
#	# $(NAME): $(OBJS) $(DEP)
#	#     ar -rc $@ $(OBJS)
#	#     @ranlib $@
#	# $(ODIR):
#	#     mkdir -p $@
#	# $(ODIR)/%.o: %.c
#	#     $(CC) $(CFLAGS) -c -o $@ $<
#	# clean:
#	#     /bin/rm -rf $(ODIR)
#	# fclean: clean
#	#     /bin/rm -f $(NAME)
#	# re: fclean all
#	# .PHONY: all clean fclean re
#
#	# prompt "make" execute the first rule ("all")
#
#	[archtecture]
#	# srcs/
#	#    function01.c
#	#    function02.c
#	# includes/
#	#    header.h
#	# builds/
#	#    function01.o
#	#    function02.o
#	# libtest.a
#	# Makefile
#
# -----
#
# NAME   = libtest.a
#
# name is now the name of the library to be built
#
# -----
#
# @ranlib $@
#
# @ tells makefile not to show the line in prompt
#

#
# THE END
# enjoy, futur me
#
