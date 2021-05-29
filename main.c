#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include <math.h>
#include "libft_bonus.h"
#include "convert.h"
#include "specifier.h"

#ifndef TESTMODE
# define TESTMODE 2
#endif
#define TEST_SPECIFIER "f"

#if TESTMODE == 0
# define TEST(...) printf(__VA_ARGS__)
#elif TESTMODE == 1
# define TEST(...) ft_printf(__VA_ARGS__)
#elif TESTMODE == 2
# define GET_FIRST_ARG(ARG, ...) ARG
# define TEST(...) \
	printf("\n[%s]\nyou: |",  GET_FIRST_ARG(__VA_ARGS__)); \
	__ret1 = ft_printf(__VA_ARGS__); \
	printf("| -> %d\nans: |", __ret1); \
	__ret2 = printf(__VA_ARGS__); \
	printf("| -> %d\n", __ret2)
#endif

#define INIT_TEST() \
	int __ret1; \
	int __ret2; \
	setvbuf(stdout, NULL, _IONBF, 0);
#define test(...) TEST(__VA_ARGS__)

int run_test(void);

int main(void)
{
#if TESTMODE != 2
	for (int i = 0; i < 1000; i++)
		run_test();
#else
	run_test();
#endif
	return (0);
}

int run_test(void)
{
	INIT_TEST();

	long double num = -1234.5891727419283478912371465745674567456234123L;
	float numf = -1234.5891727419283478912371465745674567456234123f;

	TEST("%L"TEST_SPECIFIER, num);
	TEST("%.70L"TEST_SPECIFIER, num);
	TEST("%8.L"TEST_SPECIFIER, num);
	TEST("%#8.L"TEST_SPECIFIER, num);
	TEST("%+#8.L"TEST_SPECIFIER, num);
	TEST("% .L"TEST_SPECIFIER, num);
	TEST("%+ .L"TEST_SPECIFIER, num);
	TEST("%.70L"TEST_SPECIFIER, -num);
	TEST("%L"TEST_SPECIFIER, -num);
	TEST("%8.L"TEST_SPECIFIER, -num);
	TEST("%#8.L"TEST_SPECIFIER, -num);
	TEST("%+#8.L"TEST_SPECIFIER, -num);
	TEST("% .L"TEST_SPECIFIER, -num);
	TEST("%+ .L"TEST_SPECIFIER, -num);
	TEST("%.70"TEST_SPECIFIER, numf);
	TEST("%"TEST_SPECIFIER, numf);
	TEST("%8."TEST_SPECIFIER, numf);
	TEST("%#8."TEST_SPECIFIER, numf);
	TEST("%+#8."TEST_SPECIFIER, numf);
	TEST("% ."TEST_SPECIFIER, numf);
	TEST("%+ ."TEST_SPECIFIER, numf);
	TEST("%.70"TEST_SPECIFIER, -numf);
	TEST("%"TEST_SPECIFIER, -numf);
	TEST("%8."TEST_SPECIFIER, -numf);
	TEST("%#8."TEST_SPECIFIER, -numf);
	TEST("%+#8."TEST_SPECIFIER, -numf);
	TEST("% ."TEST_SPECIFIER, -numf);
	TEST("%+ ."TEST_SPECIFIER, -numf);
	test("%1"TEST_SPECIFIER, -1.5);
	test("%1"TEST_SPECIFIER, -1.05);
	test("%1"TEST_SPECIFIER, -1.005);
	test("%1"TEST_SPECIFIER, -1.0625);
	test("%1"TEST_SPECIFIER, -14353453453423.899999999999999999999999999999999);
	test("%1"TEST_SPECIFIER, -14353453453423.0899999999999999999999999999999999);
	test("%.0"TEST_SPECIFIER, 0.5);
	test("%.0"TEST_SPECIFIER, 1.5);
	test("%.0"TEST_SPECIFIER, -0.5);
	test("%.0"TEST_SPECIFIER, -1.5);
	test("% 0-7.1"TEST_SPECIFIER, 7.3);
	test("% 0#7.1"TEST_SPECIFIER, 7.3);
	test("%0#7.1"TEST_SPECIFIER, 7.3);
	// test("% 0#-05.3"TEST_SPECIFIER, -0.0); // timeout
	// test("% 0#-05.3"TEST_SPECIFIER, 0.0); // timeout
	test("%.10"TEST_SPECIFIER, 23.000000041);
	test("%.12"TEST_SPECIFIER, 1.025978541236587568);
	test("% +.3"TEST_SPECIFIER, -7.3);
	test("% 05.0"TEST_SPECIFIER, -7.3);
	test("%.1"TEST_SPECIFIER, -3.85);
	test("%."TEST_SPECIFIER, 0.4);
	test("%."TEST_SPECIFIER, 0.5);
	test("%."TEST_SPECIFIER, 0.6);
	test("%."TEST_SPECIFIER, -0.4);
	test("%."TEST_SPECIFIER, -0.5);
	// test("%#L"TEST_SPECIFIER, 10e100000L);
	test("%."TEST_SPECIFIER, 2.50000000001);
	test("%."TEST_SPECIFIER, -0.6);
	test("%+6"TEST_SPECIFIER, 0.0/0.0);
	test("% "TEST_SPECIFIER, 0.0/0.0);
	// test("% .7"TEST_SPECIFIER, 0.0/0.0);
	// TEST("%3c", 'a');
	// TEST("%02%");
	// TEST("%p", 0x123a);
	// TEST("%.p", NULL);
	TEST("%.d", 0);
	// TEST("%20.30p", 0x1234f);
	// TEST("% +20.30q %d%d", 0x1234f, 1234, 4321);
	// TEST("%"TEST_SPECIFIER, 1234000000000000000000000000000000000000000000000000000000000000000000000000000.f);
	// TEST("%"TEST_SPECIFIER, __FLT_MAX__);
	// TEST("%"TEST_SPECIFIER, __FLT_MAX__ + 1.0f);
	// TEST("%"TEST_SPECIFIER, __FLT_MAX__ + 2.0f);
	// test("%.*"TEST_SPECIFIER, -3, 3.1415926535);

	// printf("%d vs %d vs %d\n", sizeof(float), sizeof(double), sizeof(long double));
	return (0);
}
