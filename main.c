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
#define TEST_SPECIFIER "e"

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

void	run_test(void);
void	test_42tester(void);

void	temp_test(void)
{
	INIT_TEST();
	TEST("%f", 8.5f);
	TEST("%L"TEST_SPECIFIER, 1.9999996L);
	TEST("%L"TEST_SPECIFIER, 1.05L);
	TEST("%L"TEST_SPECIFIER, 1.5L);
	TEST("%L"TEST_SPECIFIER, 3.L);
	TEST("%L"TEST_SPECIFIER, 0.75L);
	// TEST("%L"TEST_SPECIFIER, 0.05L);
	// TEST("%L"TEST_SPECIFIER, 0.5L);
	TEST("%L"TEST_SPECIFIER, 1.L);
	TEST("%L"TEST_SPECIFIER, 1.5L);
	// TEST("%L"TEST_SPECIFIER, 234.3L);
}
void	bigint_divide_2_base10(t_bigint *bigint);

int		main(void)
{
#if TESTMODE != 2
	for (int i = 0; i < 1000; i++)
		run_test();
#else
	run_test();
	// temp_test();
	// test_42tester();

	// t_bigint *bigint = make_bigint(7, 10);
	// bigint_set_digit(bigint, 5, 0);
	// bigint_set_digit(bigint, 0, 1);
	// bigint_set_digit(bigint, 0, 2);
	// bigint_set_digit(bigint, 0, 3);
	// bigint_set_digit(bigint, 0, 4);
	// bigint_set_digit(bigint, 5, 5);
	// bigint_set_digit(bigint, 1, 6);
	// bigint_inspect_decimal(bigint);
	// bigint_divide_2_base10(bigint);
	// bigint_inspect_decimal(bigint);
	// free_bigint(bigint);
#endif
	return (0);
}

void	run_test(void)
{
	INIT_TEST();

	long double num = -4321.5891727419283478912371465745674567456234123L;
	float numf = -4321.5891727419283478912371465745674567456234123f;

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
	test("% "TEST_SPECIFIER, 1e+3);
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
	TEST("%.4L"TEST_SPECIFIER, 9.9999L);
	TEST("%.3L"TEST_SPECIFIER, 9.9999L);
	TEST("%.L"TEST_SPECIFIER, 0.9L);
}

void	test_42tester(void)
{
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

	INIT_TEST();
	TEST("Simple input test");
	TEST("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", i, j, k, l, m, n, c, c, j, j, j); //T2
	TEST("%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d", i, j, k, l, m, c, e, d); //T3
	TEST("%1i, %1d, %1d, %1d, %1d, %1d, %1d, %1d", i, j, k, l, m, c, e, d); //T4
	TEST("%2i, %2d, %2d, %2d, %2d, %2d, %2d, %2d", i, j, k, l, m, c, e, d); //T5
	TEST("%3i, %3d, %3d, %3d, %3d, %3d, %3d, %3d", i, j, k, l, m, c, e, d); //T6
	TEST("%4i, %4d, %4d, %4d, %4d, %4d, %4d, %4d", i, j, k, l, m, c, e, d); //T7
	TEST("%5i, %5d, %5d, %5d, %5d, %5d, %5d, %5d", i, j, k, l, m, c, e, d); //T8
	TEST("%6i, %6d, %6d, %6d, %6d, %6d, %6d, %6d", i, j, k, l, m, c, e, d); //T9
	TEST("%7i, %7d, %7d, %7d, %7d, %7d, %7d, %7d", i, j, k, l, m, c, e, d); //T10
	TEST("%8i, %8d, %8d, %8d, %8d, %8d, %8d, %8d", i, j, k, l, m, c, e, d); //T11
	TEST("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d", i, j, k, l, m, c, e, d); //T12
	TEST("%.0i, %.0d, %.0d, %.0d, %.0d, %.0d, %.0d, %.0d", i, j, k, l, m, c, e, d); //T13
	TEST("%0.0i, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d", i, j, k, l, m, c, e, d); //T14
	TEST("%-0i, %-0d, %-0d, %-0d, %-0d, %-0d, %-0d, %-0d", i, j, k, l, m, c, e, d); //T15
	TEST("%0-i, %0-d, %0-d, %0-d, %0-d, %0-d, %0-d, %0-d", i, j, k, l, m, c, e, d); //T16
	TEST("%-.i, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d, %-.d", i, j, k, l, m, c, e, d); //T17
	TEST("%-.0i, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d", i, j, k, l, m, c, e, d); //T18
	TEST("%-i, %-d, %-d, %-d, %-d, %-d, %-d, %-d", i, j, k, l, m, c, e, d); //T19
	TEST("%.i, %.d, %.d, %.d, %.d, %.d, %.d, %.d", i, j, k, l, m, c, e, d); //T20
	TEST("%-0.0i, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d", i, j, k, l, m, c, e, d); //T21
	TEST("%00i, %00d, %00d, %00d, %00d, %00d, %00d, %00d", i, j, k, l, m, c, e, d); //T22
	TEST("%1.i, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d, %1.d", i, j, k, l, m, c, e, d); //T23
	TEST("%.1i, %.1d, %.1d, %.1d, %.1d, %.1d, %.1d, %.1d", i, j, k, l, m, c, e, d); //T24
	TEST("%1.1i, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d", i, j, k, l, m, c, e, d); //T25
	TEST("%-1i, %-1d, %-1d, %-1d, %-1d, %-1d, %-1d, %-1d", i, j, k, l, m, c, e, d); //T26
	TEST("%-01i, %-01d, %-01d, %-01d, %-01d, %-01d, %-01d, %-01d", i, j, k, l, m, c, e, d); //T27
	TEST("%-1.i, %-1.d, %-1.d, %-1.d, %-1.d, %-1.d, %-1d, %-1d", i, j, k, l, m, c, e, d); //T28
	TEST("%-.1i, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d", i, j, k, l, m, c, e, d); //T29
	TEST("%-0.1i, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d", i, j, k, l, m, c, e, d); //T30
	TEST("%-1.0i, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d", i, j, k, l, m, c, e, d); //T31
	TEST("%-1.1i, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d", i, j, k, l, m, c, e, d); //T32
	TEST("%1.0i, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d", i, j, k, l, m, c, e, d); //T33
	while (a < 5) //T34-69
	{
		TEST("%*i, %*d, %*d, %*d, %*d, %*d, %*d, %*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		TEST("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d, %0*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		TEST("%-*i, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d, %-*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		TEST("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c, a, e, a, d);
		a++;
	}
	a = -2;
	while(a < 5) //T70-177
	{
		b = -2;
		while (b < 5)
		{
			TEST("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
			TEST("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
			TEST("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c, a, b, e, a, b, d);
			b++;
		}
		a++;
	}
	a = 19;
	b = 14;
	TEST("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", a, b, -42, a, b, 42, -a, -b, -42, -a, -b, 42, -a, b, -42, -a, b, 42, a, -b, -42, a, -b, 42); //T178
	TEST("%12.12i, %12.12d", -42, 42); //T179
	TEST("%1s, %1s, %1s, %1s, %1s", n, o, p, q, r); //T180
	TEST("%2s, %2s, %2s, %2s, %2s", n, o, p, q, r); //T181
	TEST("%3s, %3s, %3s, %3s, %3s", n, o, p, q, r); //T182
	TEST("%4s, %4s, %4s, %4s, %4s", n, o, p, q, r); //T183
	TEST("%15s, %15s, %15s, %15s, %15s", n, o, p, q, r); //T184
	TEST("%16s, %16s, %16s, %16s, %16s", n, o, p, q, r); //T185
	TEST("%17s, %17s, %17s, %17s, %17s", n, o, p, q, r); //T186
	TEST("%.s, %.s, %.s, %.s, %.s", n, o, p, q, r); //T186
	TEST("%1.s, %1.s, %1.s, %1.s, %1.s", n, o, p, q, r); //T186
	a = -4;
	while (a < 5) //T187-213
	{
		TEST("%*s, %*s, %*s, %*s, %*s, %*s, %*s, %*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u);
		TEST("%-*s, %-*s, %-*s, %-*s, %-*s, %-*s, %-*s, %-*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u);
		TEST("%.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s, %.*s", a, n, a, o, a, p, a, q, a, r, a, s, a, t, a, u);
		a++;
	}
	a = -2;
	while(a < 5) //T70-177
	{
		b = -2;
		while (b < 5)
		{
			TEST("%*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s, %*.*s", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u);
			TEST("%-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u);
			b++;
		}
		a++;
	}

	TEST("%u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X", i, i, i, j, j, j, k, k, k, l, l, l, m, m, m, c, c, c, d, d, d, e, e, e); //T214
	a = -1;
	while (a < 5) //T214-256
	{
		TEST("%*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e);
		TEST("%0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e);
		TEST("%-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e);
		TEST("%.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e);
		a++;
	}
	a = -1;
	while(a < 5) //T257-346
	{
		b = -1;
		while (b < 5)
		{
			TEST("%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
			TEST("%0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
			TEST("%-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
			b++;
		}
		a++;
	}
	TEST("%p, %x, %p, %x, %p, %x, %p, %x", (void *)209590960, 209590960, (void *)207038912, 207038912, (void *)1, 1, NULL, 0); //T347
	a = 8;
	while (a < 12) //
	{
		TEST("%*p, %*x, %*p, %*x, %*p, %*x, %*p, %*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0);
		TEST("%-*p, %-*x, %-*p, %-*x, %-*p, %-*x, %-*p, %-*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0);
		a++;
	}
	a = f;
	b = g;
	TEST("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c);
	TEST("%-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s, %-*.*s", a, b, n, a, b, o, a, b, p, a, b, q, a, b, r, a, b, s, a, b, t, a, b, u);
	TEST("%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
	TEST("%-*p, %-*x, %-*p, %-*x, %-*p, %-*x, %-*p, %-*x", a, (void *)209590960, a, 209590960, a, (void *)207038912, a, 207038912, a, (void *)1, a, 1, a, NULL, a, 0);

	a = 12;
	b = 18;
	TEST("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", c, n[0], o[0], a, p[0], a, q[0], a, r[0], a, c);
	TEST("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", c, n[0], o[0], -a, p[0], -a, q[0], -a, r[0], -a, c);
	TEST("%c,  %-c, %1c, %*c,  %-*c,  %*c, %-*c", c, n[0], q[0], a, q[0], a, p[0], a, p[0], a, c);
	TEST("%c,  %-c, %1c, %*c,  %-*c,  %*c", -12, -1, -255, a, -12, a, -1, a, -255);
	TEST("%%, \t, \\, \", \', +");
	TEST("%%%dbada%s%%**%s**-d%%0*d%-12s0*@", h, "bada", r, p, r, r, i, r, i, r, i);
	TEST("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, i, a, i, a, i, a, i, a, i);
	TEST("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, j, a, j, a, j, a, j, a, j);
	TEST("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, l, a, l, a, l, a, l, a, l);
	TEST("%i, %d, %d, %d, %d, %d, %u, %x, %X", 0, 0, 0, 0, 0, 0, 0, 0, 0);
	TEST("%*i, %*d, %*d, %*d, %*d, %*d, %*u, %*x, %*X", a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0, a, 0);
	TEST("%c, %-c, %12c, %-3c, %-1c, %1c, %-2c, %-4c, %5c, %3c, %-*c, %-*c, %*c, %*c", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0);
	TEST("%-2s, %.s, %-4s, %-2.4s, %-8.12s, %3s, %8s, %---2s, %.*s, %.0s, %.1s, %.2s, %.4s, %.8s", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, -2, NULL, NULL, NULL, NULL, NULL, NULL);
	// ^ Theoriquement un comportement indefini mais testé par la moulinette
    TEST("(null)");
	TEST("");
}
