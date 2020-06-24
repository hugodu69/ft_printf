#include "libft.h"

#include <stdio.h>

char	touppercase(unsigned int i, char c)
{
	if (i < 3 && c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

void	print_ft_itoa(int i)
{
	printf("itoa   : %d -> '%s'\n", i, ft_itoa(i));
}

void	print_ft_split(char *str, char c)
{
	char	**tab;

	printf("split  : [%s] [%c] -> ", str, c);
	tab = ft_split(str, c);
	while (tab && *tab != NULL)
		printf("[%s]", *(tab++));
	printf("\n");
}

void	print_ft_strjoin(char *s1, char *s2)
{
	printf("join   : '%s' + '%s' -> '%s'\n", s1, s2, ft_strjoin(s1, s2));
}

void	print_ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	printf("mapi   : '%s' ", s);
	if (f)
		printf("'touppercase' -> ");
	else
		printf("(null) -> ");
	printf("'%s'\n", ft_strmapi(s, f));
}

void	print_ft_substr(char const *s, unsigned int start, size_t len)
{
	printf("substr : [%s](%u,%zu) -> ", s, start, len);
	printf("'%s'\n", ft_substr(s, start, len));
}

void	print_ft_strtrim(char const *s, char const *set)
{
	printf("strtrim: [%s] [%s] -> '%s'\n", s, set, ft_strtrim(s, set));
}

void	print_ft_putnbr_fd(int n, int fd)
{
	write(1, "putnbr : [", 10);
	ft_putnbr_fd(n, 1);
	write(1, "] [", 3);
	ft_putnbr_fd(fd, 1);
	write(1, "] -> '", 6);
	ft_putnbr_fd(n, fd);
	write(1, "'\n", 2);
}

int main()
{
	char	touppercase(unsigned int, char);

	printf("ITOA :\n");

	print_ft_itoa(1338);
	print_ft_itoa(0);
	print_ft_itoa(-1);
	print_ft_itoa(1);
	print_ft_itoa(-1218927987);
	print_ft_itoa(128979827);
	print_ft_itoa(2147483647);
	print_ft_itoa(-2147483648);
	print_ft_itoa('t');

	printf("\nSPLIT :\n");

	print_ft_split(" dfs zfe f ez f fez  ", ' ');
	print_ft_split(NULL, 0);
	print_ft_split(NULL, ' ');
	print_ft_split("", 0);
	print_ft_split("vzevzev fze", 0);
	print_ft_split(" ", 0);
	print_ft_split("", ' ');
	print_ft_split(" ", ' ');
	print_ft_split("zlkefj ljef jl", '\0');
	print_ft_split("zd\nazd\nds", '\n');
	print_ft_split("          ", ' ');

	printf("\nJOIN :\n");

	print_ft_strjoin("alpha", "bravo");
	print_ft_strjoin("", "");
	print_ft_strjoin(NULL, NULL);
	print_ft_strjoin("", "fskjfhkj");
	print_ft_strjoin(NULL, "");
	print_ft_strjoin(NULL, "fsdf");
	print_ft_strjoin("", NULL);
	print_ft_strjoin("sdffez", NULL);
	print_ft_strjoin("           ", "          ");

	printf("\nMAPI :\n");

	print_ft_strmapi("truc", touppercase);
	print_ft_strmapi("truc", NULL);
	print_ft_strmapi(NULL, touppercase);
	print_ft_strmapi(NULL, NULL);
	print_ft_strmapi("", touppercase);
	print_ft_strmapi("    ", touppercase);
	print_ft_strmapi("mlekgmlzkge", touppercase);
	print_ft_strmapi("\0", touppercase);
	print_ft_strmapi("f f f f", touppercase);

	printf("\nSUB :\n");

	print_ft_substr("zeff", 3, 4);
	print_ft_substr(NULL, 1, 1);
	print_ft_substr("srgz", 0, 0);
	print_ft_substr("setzettzetzet", -1, -1);
	print_ft_substr("ggzrg", -1, 3);
	print_ft_substr("", 3, 2);
	print_ft_substr("regrehehzhzh", 1, 23);
	print_ft_substr("gzrgzgb zeez", 11, 0);
	print_ft_substr("gzrgzgb zeez", 1123238713, 0);
	print_ft_substr("gzrgzgb zeez", 1123238713, 2873981730);
	print_ft_substr("gzrgzgb zeez", 1, 2873981730);

	printf("\nTRIM :\n");

	print_ft_strtrim("   stmr trim ", "m ");
	print_ft_strtrim("                 ", " ");
	print_ft_strtrim("", "");
	print_ft_strtrim(NULL, "");
	print_ft_strtrim("", NULL);
	print_ft_strtrim(NULL, NULL);
	print_ft_strtrim("efzfe fzef", "");
	print_ft_strtrim("efzfzelelijz", " ");
	print_ft_strtrim("     e f zfzelelijz   ", " ");
	print_ft_strtrim("cccccccccccccccccccc", "c");

	printf("\nPUTNBR :\n");

	print_ft_putnbr_fd(52, 1);
	print_ft_putnbr_fd(2147483647, 1);
	print_ft_putnbr_fd(-2147483648, 1);
	print_ft_putnbr_fd(0, 1);
	print_ft_putnbr_fd(-1, 1);
	print_ft_putnbr_fd(239847, 1);
	print_ft_putnbr_fd(34625725, 1);
	print_ft_putnbr_fd(-4564562, 1);
	print_ft_putnbr_fd(456, 1);
	print_ft_putnbr_fd(-624724536, 1);
	return 0;
}
