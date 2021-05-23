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

typedef __uint128_t	t_itype;
void	inspect_bit(double val)
{
	t_itype	bitmask = (t_itype)0b1 << (sizeof(t_itype) * 8 - 1);
	t_itype	b;

	ft_memcpy(&b, &val, sizeof(val));
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

int main(void)
{
	INIT_TEST();

	// printf("hello world %d\n", 10);
	// printf("hello world %d\n", 10);
	ft_printf("asdf");

	uintmax_t umaxint = UINTMAX_MAX;

	TEST("%ju", umaxint);

	TEST("%s", (char *)0);
	printf("%llu\n", ULLONG_MAX);

	inspect_bit(8.5);

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

	printf("%d vs %d vs %d\n", sizeof(float), sizeof(double), sizeof(long double));
	return (0);
}
