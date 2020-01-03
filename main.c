#include <libc.h>

int		main(void)
{

	printf("- conversions : cspdiuxX%% ---------------------\n");
	printf("------- flags : -0.* --------------------------\n\n");

	printf("(\"%%X\",8645)       : ");
	printf("'%X' \n", 8645);

	printf("(\"%%04X\",8645)     : ");
	printf("'%04X' \n", 8645);

	printf("(\"%%07X\",8645)     : ");
	printf("'%07X' \n", 8645);

	printf("(\"%%7X\",8645)      : ");
	printf("'%7X' \n", 8645);

	printf("(\"%%.7X\",8645)     : ");
	printf("'%.7X' \n", 8645);

	printf("(\"%%7.7X\",8645)    : ");
	printf("'%7.7X' \n", 8645);

	printf("(\"%%10.7X\",8645)   : ");
	printf("'%10.7X' \n", 8645);

	printf("(\"%%010.7X\",8645)  : ");
	printf("'%010.7X' \n", 8645);

	printf("(\"%%010X\",8645)    : ");
	printf("'%010X' \n", 8645);

	printf("\n");

	printf("(\"%%#X\",8645)      : ");
	printf("'%#X' \n", 8645);

	printf("(\"%%#.7X\",8645)    : ");
	printf("'%#.7X' \n", 8645);

	printf("(\"%%#010.7X\",8645) : ");
	printf("'%#010.7X' \n", 8645);

	printf("(\"%%#10.7X\",8645)  : ");
	printf("'%#10.7X' \n", 8645);

	printf("(\"%%#10X\",8645)    : ");
	printf("'%#10X' \n", 8645);

	printf("(\"%%#.10X\",8645)   : ");
	printf("'%#.10X' \n", 8645);

	printf("(\"%%#10.10X\",8645) : ");
	printf("'%#10.10X' \n", 8645);

	printf("(\"%%#010X\",8645)   : ");
	printf("'%#010X' \n", 8645);

	return (0);
}

	//	usage :
	//	%[flags][width][.precision][length]specifier
	//
	//	[specifiers]
	//	c		character
	//	s		string of characters
	//	p		pointer adress
	//	d		(or i) signed decimal integer
	//	i		(or d) signed decimal integer
	//	u		unsigned decimal integer
	//	x		unsigned hexadecimal integer
	//	X		unsigned hexadecimal integer (capital letters)
	//(	n		nothing printed
	//(	f		decimal floating point
	//(	g		uses the shorter of %e or %f
	//(	e		scientific notation (mantissa/exponent) using e
	//((E		scientific notation (mantissa/exponent) using E
	//((G		uses the shorter of %E or %f
	//((o		signed octal
	//
	//	[flags]
	//	-		left-justify within the given field width
	//	0		left-pads the number with zeroes (0) instead of spaces, where
	//			padding is specified (see width sub-specifier)
	//(	+		forces to precede the result with a plus or minus sign even for
	//			positive numbers)
	//(	(space)	if no sign is going to be written, a blank space is inserted
	//			before the value)
	//(	#		used with o, x or X specifiers the value is preceded with 0, 0x
	//			or 0X respectively for values different than zero. Used with e,
	//			E and f, it forces the written output to contain a decimal point
	//			even if no digits would follow. By default, if no digits follow,
	//			no decimal point is written. Used with g or G the reult is the
	//			same as with e or E but trailing zeros are not removed)
	//
	//	[width]
	//	(nbr)	minimum number of characters to be printed. if the value to be
	//			printed is shorter than this number, the result is padded with
	//			blank spaces. The value is not truncated even if the result is
	//			larger
	//	*		the width is not specified in the format string, but as an
	//			additional integer value argument preceding the argument that
	//			has to be formatted
	//
	//	[.precision]
	//	.nbr	fot integer specifiers (d,i,o,x,X) - precision specifies the
	//			minimum number of digits to be written. If the value to be
	//			written is shorter than this number, the result is padded with
	//			leading zeros. The value is not truncated even if the result is
	//			longer. A precision of 0 means that no character is written for
	//			the value 0. For e, E and f specifiers − this is the number of
	//			digits to be printed after the decimal point. For g and G
	//			specifiers − This is the maximum number of significant digits
	//			to be printed. For s − this is the maximum number of characters
	//			to be printed. By default all characters are printed until the
	//			ending null character is encountered. For c type − it has no
	//			effect. When no precision is specified, the default is 1. If the
	//			period is specified without an explicit value for precision, 0
	//			is assumed
	//	.*		the precision is not specified in the format string, but as an
	//			additional integer value argument preceding the argument that
	//			has to be formated
	//
