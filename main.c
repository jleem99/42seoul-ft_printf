#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	printf("%d\n", ft_printf("hello%world", 1234, 1234));
	return (0);
}
