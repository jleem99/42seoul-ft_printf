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


	TEST("%3c", 'a');
	TEST("%02%");

	return (0);
}
