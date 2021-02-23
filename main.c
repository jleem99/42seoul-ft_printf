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
	// printf("\n%d\n", ft_printf("he%c", 'a'));
	// printf("%++++++++++0+#40.*f", 10, 1234.5678);
	// printf("%.g", 1234.234239487);
	printf("Characters: %c %c\n", 'a', 65);
	ft_printf("Characters: %c %c\n", 'a', 65);
	printf("\n");
	printf("Decimals: %d %ld\n", -1977, 650000L);
	ft_printf("Decimals: %d %ld\n", -1977, 650000L);
	printf("\n");
	printf("Preceding with blanks: %10d\n", 1977);
	ft_printf("Preceding with blanks: %10d\n", 1977);
	printf("\n");
	printf("Preceding with zeros: %010d\n", 1977);
	ft_printf("Preceding with zeros: %010d\n", 1977);
	printf("\n");
	printf("Some different radices: %d %x %o %#x %#o\n", 100, 100, 100, 0xA8C, 100);
	ft_printf("Some different radices: %d %x %o %#x %#o\n", 100, 100, 100, 0xA8C, 100);
	printf("\n");
	printf("floats: %4.2f %+.0e %E\n", 3.1416, 3.1416, 3.1416);
	ft_printf("floats: %4.2f %+.0e %E\n", 3.1416, 3.1416, 3.1416);
	printf("\n");
	printf("Width trick: %*d\n", 5, 10);
	ft_printf("Width trick: %*d\n", 5, 10);
	printf("\n");
	printf("Percent sign: %%\n");
	ft_printf("Percent sign: %%\n");
	printf("\n");
	printf("%020s\n", "A string");
	ft_printf("%020s\n", "A string");
	printf("\n");
	printf("%s\n", NULL);


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

	printf("%*p, %*x\n", a, (void *)1234, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0);
	ft_printf("%*p, %*x\n", a, (void *)1234, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0);
	// ft_printf(" --- Return : %d\n", ft_printf("%*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0));

	return (0);
}
