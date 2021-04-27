#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	ft_printf("%7*.*d\n", 1, 3, 5);
	printf("%7*.*d\n", 1, 3, 5);
	return (0);
}
