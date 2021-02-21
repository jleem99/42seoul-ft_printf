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
	ft_printf("Characters: %c %c \n", 'a', 65);
	ft_printf("Decimals: %d %ld\n", -1977, 650000L);
	ft_printf("Preceding with blanks: %10d \n", 1977);
	ft_printf("Preceding with zeros: %010d \n", 1977);
	ft_printf("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
	ft_printf("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	ft_printf("Width trick: %*d \n", 5, 10);
	ft_printf("Percent sign: %%\n");
	ft_printf("%020s \n", "A string");
	printf("\n\n%020s", "hello world");
	return (0);
}
