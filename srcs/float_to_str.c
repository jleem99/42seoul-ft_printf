/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_to_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 01:09:46 by jleem             #+#    #+#             */
/*   Updated: 2021/05/26 01:39:28 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float_to_str.h"
#include "bigint.h"
#include "libft_bonus.h"
#include <stdlib.h>

int			ieee854_get_unbiased_exponent(t_ieee854 ieee854)
{
	return (ieee854.ieee.exponent - IEEE854_LONG_DOUBLE_BIAS);
}

/*
** Get mantissa bits: [start_bit, end_bit)
*/

uint64_t	ieee854_get_mantissa(t_ieee854 ieee854, int start_bit, int end_bit)
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

t_bigint	*ieee854_get_integer_part(t_ieee854 ieee854)
{
	int const	num_bits = ieee854_get_unbiased_exponent(ieee854) + 1;
	int			leftover_bits;
	uint64_t	mantissa_integer;
	t_bigint	*integer;
	int			digit_idx;

	integer = make_bigint(0, 10);
	mantissa_integer = ieee854_get_mantissa(ieee854, 0, num_bits);
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

t_bigint	*ieee854_get_decimal_part(t_ieee854 ieee854)
{
	int const	unused_bits = ieee854_get_unbiased_exponent(ieee854) + 1;
	uint64_t	mantissa_decimal;
	t_bigint	*decimal;
	int			decimalifier;
	int			digit_idx;

	decimal = make_bigint(0, 10);
	if (unused_bits >= 64)
		return (decimal);
	mantissa_decimal = ieee854_get_mantissa(ieee854, unused_bits, 64);
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
// Todo: round_idx < 0
static void	round_number(t_bigint *integer, t_bigint *decimal, int precision)
{
	size_t const	round_idx = decimal->size - (precision + 1);
	int				round = decimal->size > (precision + 1) &&
							decimal->data[round_idx] >= 5;

	if (round)
	{
		if (precision == 0)
			integer->data[0] += round;
		else
			decimal->data[round_idx + 1] += round;
	}
	bigint_resize_reverse(decimal, precision);
}

static char	*join_integer_decimal(t_bigint *integer, t_bigint *decimal)
{
	char *const		integer_str = bigint_to_string(integer);
	char *const		decimal_str = bigint_to_string(decimal);
	size_t const	integer_len = ft_strlen(integer_str);
	size_t const	decimal_len = ft_strlen(decimal_str);
	char			*str;

	if (decimal_len > 0)
	{
		str = malloc(integer_len + decimal_len + 2);
		ft_strcpy(str, integer_str);
		str[integer_len] = '.';
		ft_strcpy(str + integer_len + 1, decimal_str);
	}
	else
	{
		str = ft_strdup(integer_str);
	}
	free(integer_str);
	free(decimal_str);
	return (str);
}

char		*long_double_to_str_10(long double flt, int precision)
{
	t_ieee854 const	ieee854 = { flt };
	t_bigint *const	integer = ieee854_get_integer_part(ieee854);
	t_bigint *const	decimal = ieee854_get_decimal_part(ieee854);
	char			*str;

	round_number(integer, decimal, precision);
	str = join_integer_decimal(integer, decimal);
	free_bigint(integer);
	free_bigint(decimal);
	return (str);
}
