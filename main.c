#include "ft_printf.h"
#include <stdio.h>

#include <stdlib.h>

#include <limits.h>
#include <stdint.h>

#define INIT_TEST() \
	int __ret1; \
	int __ret2; \
	setvbuf(stdout, NULL, _IONBF, 0);

#define TEST(...) \
	printf("\nyou: |"); \
	__ret1 = ft_printf(__VA_ARGS__); \
	printf("| -> %d\nans: |", __ret1); \
	__ret2 = printf(__VA_ARGS__); \
	printf("| -> %d\n", __ret2);

#define test(...) TEST(__VA_ARGS__)

#include <math.h>
#include <libft.h>

typedef __uint128_t	t_mtype;
typedef float		t_itype;
void	inspect_bit(t_itype val)
{
	t_mtype	bitmask = (t_mtype)0b1 << (sizeof(t_mtype) * 8 - 1);
	t_mtype	b;

	ft_bzero(&b, sizeof(t_mtype));
	ft_memcpy(&b, &val, sizeof(t_itype));
	char counter = 0;
	for (; bitmask != 0; bitmask >>= 1)
	{
		printf("%d", (b & bitmask) != 0);
		counter++;
		if (counter % 32 == 0)
			printf("\n");
		else if (counter % 8 == 0)
			printf(" ");
	}
	printf("\n");
}

#include "bigint.h"
#include "float_to_str.h"

int main(void)
{
	// long_double_to_str_10(1.0L/0.0L, 10);
	// printf("\n");
	long_double_to_str_10(-123.5L, 10);
	printf("\n");
	long_double_to_str_10(8.75L, 10);









	// INIT_TEST();
	// TEST("%3c", 'a');
	// TEST("%02%");
	// TEST("%p", 0x123a);
	// TEST("%.p", NULL);
	// TEST("%.d", 0);
	// TEST("%20.30p", 0x1234f);
	// TEST("% +20.30q %d%d", 0x1234f, 1234, 4321);
	// TEST("%f", 1234000000000000000000000000000000000000000000000000000000000000000000000000000.f);
	// TEST("%f", __FLT_MAX__);
	// TEST("%f", __FLT_MAX__ + 1.0f);
	// TEST("%f", __FLT_MAX__ + 2.0f);
	// test("%.*f", -3, 3.1415926535);

	// long double num = 1231234189237489172341928347891237123412341234419234.6;
	// long double divider = 1;
	// while (num > 10)
	// {
	// 	TEST("%Lf", num);
	// 	num /= 10;
	// }

	// printf("%d vs %d vs %d\n", sizeof(float), sizeof(double), sizeof(long double));
	return (0);
}
