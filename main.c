#include "printf.h"

int		main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	if (ac == 2)
		ft_printf(av[1]);
	if (ac == 3)
		ft_printf(av[1], av[2]);
	if (ac == 4)
		ft_printf(av[1], av[2], av[3]);
	if (ac == 5)
		ft_printf(av[1], av[2], av[3], av[4]);
	if (ac == 6)
		ft_printf(av[1], av[2], av[3], av[4], av[5]);
	if (ac == 7)
		ft_printf(av[1], av[2], av[3], av[4], av[5], av[6]);
	if (ac == 8)
		ft_printf(av[1], av[2], av[3], av[4], av[5], av[6], av[7]);
	if (ac == 9)
		ft_printf(av[1], av[2], av[3], av[4], av[5], av[6], av[7], av[8]);
	if (ac == 10)
		ft_printf(av[1], av[2], av[3], av[4], av[5], av[6], av[7], av[8], av[9]);
	if (ac == 11)
		ft_printf(av[1], av[2], av[3], av[4], av[5], av[6], av[7], av[8], av[9], av[10]);
	if (ac == 12)
		ft_printf(av[1], av[2], av[3], av[4], av[5], av[6], av[7], av[8], av[9], av[10], av[11]);
	if (ac == 13)
		ft_printf(av[1], av[2], av[3], av[4], av[5], av[6], av[7], av[8], av[9], av[10], av[11], av[12]);
	return (0);
}
