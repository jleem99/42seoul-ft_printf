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
#include "specifier.h"
int main(void)
{
	INIT_TEST();

	sizeof(t_specifier);
	// long double num = -11234.5891727419283478912371465745674567456234123L;
	// TEST("%.70Lf", num);
	// TEST("%Lf", num);
	// TEST("%8.Lf", num);
	// TEST("%#8.Lf", num);
	// TEST("%+#8.Lf", num);
	// TEST("% .Lf", num);
	// TEST("%+ .Lf", num);
	// TEST("%.70Lf", -num);
	// TEST("%Lf", -num);
	// TEST("%8.Lf", -num);
	// TEST("%#8.Lf", -num);
	// TEST("%+#8.Lf", -num);
	// TEST("% .Lf", -num);
	// TEST("%+ .Lf", -num);
	// float numf = -11234.5891727419283478912371465745674567456234123f;
	// TEST("%.70f", numf);
	// TEST("%f", numf);
	// TEST("%8.f", numf);
	// TEST("%#8.f", numf);
	// TEST("%+#8.f", numf);
	// TEST("% .f", numf);
	// TEST("%+ .f", numf);
	// TEST("%.70f", -numf);
	// TEST("%f", -numf);
	// TEST("%8.f", -numf);
	// TEST("%#8.f", -numf);
	// TEST("%+#8.f", -numf);
	// TEST("% .f", -numf);
	// TEST("%+ .f", -numf);

	// test("%1f", -1.5);
	// test("%1f", -1.05);
	// test("%1f", -1.005);
	// test("%1f", -1.0625);
	// test("%1f", -14353453453423.899999999999999999999999999999999);
	// test("%1f", -14353453453423.0899999999999999999999999999999999);
	// test("%.0f", 0.5);
	// test("%.0f", 1.5);
	// test("%.0f", -0.5);
	// test("%.0f", -1.5);


	// test("% 0-7.1f", 7.3);
	// test("% 0#7.1f", 7.3);
	// test("%0#7.1f", 7.3);
	// // test("% 0#-05.3f", -0.0); // timeout
	// // test("% 0#-05.3f", 0.0); // timeout
	// test("%.10f", 23.000000041);
	// test("%.12f", 1.025978541236587568);
	// test("% +.3f", -7.3);
	// test("% 05.0f", -7.3);
	// test("%.1f", -3.85);
	// sizeof(long double);
	// test("%.f", 0.4);
	// test("%.f", 0.5);
	// test("%.f", 0.6);
	// test("%.f", -0.4);
	// test("%.f", -0.5);
	// // test("%#Lf", 10e100000L);

	// test("%.f", 2.50000000001);
	// test("%.f", -0.6);

	double special;
	*((unsigned long *)&special) = 0x7FF0000000100000;
	// test("%+6f", 0.0/0.0);
	test("% f", 0.0/0.0);
	// test("% .7f", 0.0/0.0);

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

	// printf("%d vs %d vs %d\n", sizeof(float), sizeof(double), sizeof(long double));
	return (0);
}
