/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_to_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 01:09:46 by jleem             #+#    #+#             */
/*   Updated: 2021/05/25 17:04:52 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float_to_str.h"
#include "bigint.h"

int			get_unbiased_exponent(t_ieee854 ieee854)
{
	return (ieee854.ieee.exponent - IEEE854_LONG_DOUBLE_BIAS);
}

/*
** Get mantissa bits [start_bit, end_bit)
*/

uint64_t	get_mantissa(t_ieee854 ieee854, int start_bit, int end_bit)
{
	uint64_t	mantissa;

	if (start_bit >= end_bit)
		return (0);
	mantissa = ieee854.ieee.mantissa0;
	mantissa <<= 32;
	mantissa |= ieee854.ieee.mantissa1;
	if (start_bit > 0)
		mantissa = (mantissa << start_bit) >> start_bit;
	if (end_bit < 64)
		mantissa >>= (64 - end_bit);
	return (mantissa);
}

t_bigint	*long_double_get_integer_part(t_ieee854 ieee854)
{
	int const	num_bits = get_unbiased_exponent(ieee854) + 1;
	int			leftover_bits;
	uint64_t	mantissa_integer;
	t_bigint	*integer;
	int			digit_idx;

	integer = make_bigint(0);
	mantissa_integer = get_mantissa(ieee854, 0, num_bits);
	leftover_bits = num_bits - 64;
	digit_idx = 0;
	while (mantissa_integer != 0)
	{
		bigint_set_digit(integer, mantissa_integer % 10, digit_idx++);
		mantissa_integer /= 10;
	}
	while (leftover_bits-- > 0)
		bigint_multiply(integer, 2);
	return (integer);
}

t_bigint	*long_double_get_decimal_part(t_ieee854 ieee854)
{
	int const	unused_bits = get_unbiased_exponent(ieee854) + 1;
	uint64_t	mantissa_decimal;
	t_bigint	*decimal;
	int			decimalifier;
	int			digit_idx;

	decimal = make_bigint(0);
	if (unused_bits >= 64)
		return (decimal);
	mantissa_decimal = get_mantissa(ieee854, unused_bits, 64);
	digit_idx = 0;
	while (mantissa_decimal != 0)
	{
		bigint_set_digit(decimal, mantissa_decimal % 10, digit_idx++);
		mantissa_decimal /= 10;
	}
	decimalifier = 64 - unused_bits;
	while (decimalifier--)
		bigint_multiply(decimal, 5);
	return (decimal);
}

char	*long_double_to_str_10(long double flt, int precision)
{
	t_ieee854 const	ieee854 = { flt };
	t_bigint const	*integer = long_double_get_integer_part(ieee854);
	t_bigint const	*decimal = long_double_get_decimal_part(ieee854, precision);

	bigint_inspect_decimal(integer);
	bigint_inspect_decimal(decimal);
	free_bigint(integer);
	free_bigint(decimal);
}

char		*long_double_to_str_16(long double flt, int precision)
{
	
}
