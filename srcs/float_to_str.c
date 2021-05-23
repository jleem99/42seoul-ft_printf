/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_to_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 01:09:46 by jleem             #+#    #+#             */
/*   Updated: 2021/05/23 23:17:45 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float_to_str.h"
#include "bigint.h"

t_size			get_unbiased_exponent(t_ieee854 ieee854)
{
	return (ieee854.ieee.exponent - IEEE854_LONG_DOUBLE_BIAS);
}

#include "libft.h"
#include <stdio.h>

__uint128_t		*long_double_extract_integer(t_ieee854 ieee854)
{
	t_size const	exponent = get_unbiased_exponent(ieee854);
	t_size const	bits = exponent + 1;
	__uint128_t		integer;

	integer = 0;
	ft_memcpy(&integer, (char *)&ieee854.d + 4, 8);
	printf("bits: %d\n", bits);
	// *((char *)integer) |= 0b10000000;
	// integer >>= (128 - bits);
	return (ieee854.ieee.mantissa0 >> 25);
}


#include <inttypes.h>
typedef unsigned __int128 uint128_t;

/*      UINT64_MAX 18446744073709551615ULL */
#define P10_UINT64 10000000000000000000ULL   /* 19 zeroes */
#define E10_UINT64 19

#define STRINGIZER(x)   # x
#define TO_STRING(x)    STRINGIZER(x)
static int print_u128_u(uint128_t u128)
{
    int rc;
    if (u128 > UINT64_MAX)
    {
        uint128_t leading  = u128 / P10_UINT64;
        uint64_t  trailing = u128 % P10_UINT64;
        rc = print_u128_u(leading);
        rc += printf("%." TO_STRING(E10_UINT64) PRIu64, trailing);
    }
    else
    {
        uint64_t u64 = u128;
        rc = printf("%" PRIu64, u64);
    }
    return rc;
}

#include <stdio.h>
#include "libft.h"
char			*long_double_to_str_10(long double flt, int precision)
{
	t_ieee854 const		ieee854 = { flt };
	t_bigint			*decimal;
	__uint128_t const	integer = long_double_extract_integer(ieee854);

	print_u128_u(integer);



	// 8.5
	// 1000.1
	// 1.0001 * 2^2
	// 11011001001101001.00100100010010001
}

char			*long_double_to_str_16(long double flt, int precision)
{
	
}
