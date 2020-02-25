#include "ft_printf.h"
#include <stdio.h> // for printf
#include <fcntl.h> // for dup() and dup2()

//#define PRINT(string)		\
//		dup2(out1, 1); \
//		ft_printf(string "\n"); \
//		dup2(out2, 1); \
//		ft_printf(string "\n"); \
//		dup2(save, 1); \
//		ft_printf(string "\n"); \
//		ft_printf(string "\n\n");

#define PRINT(string)		\
		dup2(out1, 1); \
		write(1, "printf :" string "\n", 14); \
		dup2(out2, 1); \
		write(1, "printf2:" string "\n", 14); \
		dup2(save, 1); \
		write(1, "printf :" string "\n", 14); \
		write(1, "printf2:" string "\n\n", 15); \

//#define PRINT(string)		\
//		dup2(out1, 1); \
//		printf("printf :" string "\n"); \
//		dup2(out2, 1); \
//		ft_printf("printf2:" string "\n"); \
//		dup2(save, 1); \
//		printf("printf :" string "\n"); \
//		ft_printf("printf2:" string "\n\n");

//#define PRINT(string)		\
//		printf("printf :" string "\n"); \
//		ft_printf("printf2:" string "\n\n"); \
//		dup2(out1, 1); \
//		printf("printf :" string "\n"); \
//		dup2(out2, 1); \
//		ft_printf("printf2:" string "\n"); \
//		dup2(save, 1);

int		main(void)
{
	int	out1 = open("out1.txt", O_WRONLY | O_TRUNC);
	int	out2 = open("out2.txt", O_WRONLY | O_TRUNC);
	int	save = dup(1);

	PRINT("test1");
	PRINT("test2");

	close(out1);
	close(out2);
	close(save);
	return (0);
}
