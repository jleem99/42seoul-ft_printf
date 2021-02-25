#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	// '+' > ' '
	// '-' > '0'
	// ' ' !vs '0'

	// '%o' > '0'
	// '+' vs '%o'
	// ' ' vs '%o'
	// printf("<\n%d\n", ft_printf(">he%c", 'a'));
	// printf("<%++++++++++0+#40.*f", 10, 1234.5678);
	// printf("<%.g", 1234.234239487);
	printf("<abc\n");
	ft_printf(">abc\n");
	printf("\n");
	printf("<Characters: %c %c\n", 'a', 65);
	ft_printf(">Characters: %c %c\n", 'a', 65);
	printf("\n");
	printf("<Decimals: %d %ld\n", -1977, 650000L);
	ft_printf(">Decimals: %d %ld\n", -1977, 650000L);
	printf("\n");
	printf("<Preceding with blanks: %10d\n", 1977);
	ft_printf(">Preceding with blanks: %10d\n", 1977);
	printf("\n");
	printf("<Preceding with zeros: %010d\n", 1977);
	ft_printf(">Preceding with zeros: %010d\n", 1977);
	printf("\n");
	printf("<Some different radices: %d %x %o %#x %#o\n", 100, 100, 100, 0xA8C, 100);
	ft_printf(">Some different radices: %d %x %o %#x %#o\n", 100, 100, 100, 0xA8C, 100);
	printf("\n");
	printf("<floats: %4.2f %+.0e %E\n", 3.1416, 3.1416, 3.1416);
	ft_printf(">floats: %4.2f %+.0e %E\n", 3.1416, 3.1416, 3.1416);
	printf("\n");
	printf("<Width trick: %*d\n", 5, 10);
	ft_printf(">Width trick: %*d\n", 5, 10);
	printf("\n");
	printf("<Percent sign: %%\n");
	ft_printf(">Percent sign: %%\n");
	printf("\n");
	printf("<%020s\n", "A string");
	ft_printf(">%020s\n", "A string");
	printf("\n");
	printf("<%#020x\n", 1234567);
	ft_printf(">%#020x\n", 1234567);
	// printf("\n");
	// printf("<%020#x\n", 1234567);
	// ft_printf(">%020#x\n", 1234567);
	printf("\n");
	printf("<%020p\n", (void *)1234567);
	ft_printf(">%020p\n", (void *)1234567);
	printf("\n");
	printf("<%p\n", (void *)1234567);
	ft_printf(">%p\n", (void *)1234567);
	printf("\n");
	printf("<%---0.*d\n", 12, 0);
	ft_printf(">%---0.*d\n", 12, 0);
	// printf("<%s\n", NULL);

	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	printf("\n");
	printf("<%*p, %*x\n", a, (void *)1234, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0);
	ft_printf(">%*p, %*x\n", a, (void *)1234, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0);
	// ft_printf("> --- Return : %d\n", ft_printf(">%*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));

	printf("\n");
	printf("<%.0d|\n", 0);
	ft_printf(">%.0d|\n", 0);
	printf("\n");
	printf("<%0.d|\n", 0);
	ft_printf(">%0.d|\n", 0);
	printf("\n");
	printf("<%0*.*o|\n", 1, 0, 0);
	ft_printf(">%0*.*o|\n", 1, 0, 0);
	printf("\n");
	printf("<%+d|\n", 0);
	ft_printf(">%+d|\n", 0);
	printf("\n");
	printf("<%04.3d|\n", 13);
	ft_printf(">%04.3d|\n", 13);
	printf("\n");
	printf("<%*d|\n", -4, 14);
	ft_printf(">%*d|\n", -4, 14);
	printf("\n");
	printf("<%0d|\n", 15);
	ft_printf(">%0d|\n", 15);
	printf("\n");
	printf("<%02d|\n", 0);
	ft_printf(">%02d|\n", 0);
	printf("\n");
	printf("<%.*d|\n", -4, 0);
	ft_printf(">%.*d|\n", -4, 0);
	printf("\n");
	printf("<%.*d|\n", -1, 0);
	ft_printf(">%.*d|\n", -1, 0);
	printf("\n");
	printf("<%.*d|\n", 0, 0);
	ft_printf(">%.*d|\n", 0, 0);
	printf("\n");
	printf("<%.*d|\n", 4, -12);
	ft_printf(">%.*d|\n", 4, -12);
	printf("\n");
	printf("<%0*d|\n", 4, -12);
	ft_printf(">%0*d|\n", 4, -12);
	printf("\n");
	printf("<%.3s|\n", "helloworld");
	ft_printf(">%.3s|\n", "helloworld");
	printf("\n");
	printf("<%*.*c|\n", 12, 33, 'a');
	ft_printf(">%*.*c|\n", 12, 33, 'a');

	printf("\n");
	int aaaa = printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);
	int bbbb = ft_printf("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c\n", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);
	printf("\n%dvs%d\n", aaaa, bbbb);


	printf("\n");
	printf("%d\n", printf("%3c", 0));
	printf("%d\n", ft_printf("%3c", 0));

	printf("\n");
	printf("%3c", 0);
	ft_printf("%3c", 0);

	// printf("\n");
	// printf("<à\n");
	// ft_printf(">à\n");
	return (0);
}
