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
	printf("%d\n", ft_printf("hello%world", 1234, 1234));
	printf("%++++++++++0+#40.*f", 10, 1234.5678);
	return (0);
}
