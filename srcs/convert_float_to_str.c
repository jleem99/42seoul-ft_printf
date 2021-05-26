/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_float_to_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 01:09:46 by jleem             #+#    #+#             */
/*   Updated: 2021/05/26 23:28:30 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include "libft_bonus.h"
#include <stdlib.h>

int			ieee854_get_unbiased_exponent(t_ieee854 ieee854)
{
	return (ieee854.bitfield.exponent - IEEE854_LONG_DOUBLE_BIAS);
}

int			ieee854_is_negative(long double flt)
{
	t_ieee854 const	ieee854 = { flt };

	return (ieee854.bitfield.negative);
}

// Todo: exponent == 0 -> zero (for optimization purpose)
char		*ieee854_check_reserved_bits(t_ieee854 ieee854)
{
	if (ieee854.bitfield.exponent == 32767)
	{
		if (ieee854.reserved.section0 == 0b00 ||
			ieee854.reserved.section0 == 0b01 ||
			ieee854.reserved.section0 == 0b11)
			return (ft_strdup("nan"));
		else if (ieee854.reserved.section0 == 0b10)
		{
			if (ieee854.reserved.section1 == 0)
				return (ft_strdup("inf"));
			else
				return (ft_strdup("nan"));
		}
	}
	return (NULL);
}

/*
** Get mantissa bits: [start_bit, end_bit)
*/

uint64_t	ieee854_get_mantissa(t_ieee854 ieee854, int start_bit, int end_bit)
{
	uint64_t	mantissa;

	if (start_bit >= end_bit)
		return (0);
	mantissa = ieee854.bitfield.mantissa0;
	mantissa <<= 32;
	mantissa |= ieee854.bitfield.mantissa1;
	if (start_bit > 0)
		mantissa = (mantissa << start_bit) >> start_bit;
	if (end_bit < 64)
		mantissa >>= (64 - end_bit);
	return (mantissa);
}

static void	convert_mantissa_to_bigint(t_bigint *bigint, uint64_t mantissa)
{
	int const	base = bigint->base;
	int			digit_idx;
	
	digit_idx = 0;
	while (mantissa != 0)
	{
		bigint_set_digit(bigint, mantissa % base, digit_idx);
		mantissa /= base;
		digit_idx++;
	}
}

t_bigint	*ieee854_get_integer_part(t_ieee854 ieee854)
{
	t_bigint *const	integer = make_bigint(1, 10);
	int const		num_bits = ieee854_get_unbiased_exponent(ieee854) + 1;
	int				leftover_bits;

	leftover_bits = num_bits - 64;
	convert_mantissa_to_bigint(integer,
		ieee854_get_mantissa(ieee854, 0, num_bits));
	while (leftover_bits-- > 0)
		bigint_multiply(integer, 2);
	return (integer);
}

static void	ieee854_decimalify(t_bigint *decimal, t_ieee854 ieee854)
{
	int const	num_bits = 64 - (ieee854_get_unbiased_exponent(ieee854) + 1);
	int			decimalifier;

	decimalifier = 0;
	while (decimalifier < num_bits)
	{
		bigint_multiply(decimal, 5);
		decimalifier++;
	}
	bigint_resize(decimal, num_bits); // ?? WTF
}

t_bigint	*ieee854_get_decimal_part(t_ieee854 ieee854)
{
	t_bigint *const	decimal = make_bigint(0, 10);
	int const		unused_bits = ieee854_get_unbiased_exponent(ieee854) + 1;

	if (unused_bits >= 64)
		return (decimal);
	convert_mantissa_to_bigint(decimal,
		ieee854_get_mantissa(ieee854, unused_bits, 64));
	ieee854_decimalify(decimal, ieee854);
	return (decimal);
}

static int	check_smaller_decimal_places(t_bigint *decimal, size_t round_idx)
{
	size_t	byteidx;

	byteidx = round_idx;
	while (byteidx > 0)
	{
		byteidx--;
		if (decimal->data[byteidx] != 0)
			return (1);
	}
	return (0);
}

static int	check_round_condition(t_bigint *integer, t_bigint *decimal, int precision)
{
	size_t const	round_idx = decimal->size - (precision + 1);

	if (decimal->size > (size_t)(precision + 1))
	{
		if (decimal->data[round_idx] > 5)
			return (1);
		else if (decimal->data[round_idx] == 5)
		{
			if (check_smaller_decimal_places(decimal, round_idx))
				return (1);
			else if (precision == 0)
				return (integer->data[0] % 2 == 1);
			else
				return (decimal->data[round_idx + 1] % 2 == 1);
		}
	}
	return (0);
}

// Todo: round_idx < 0

static void	round_number(t_bigint *integer, t_bigint *decimal, int precision)
{
	size_t const	decimal_original_size = decimal->size;
	size_t const	round_idx = decimal->size - (precision + 1);

	if (check_round_condition(integer, decimal, precision))
	{
		if (precision == 0)
			bigint_add_digit(integer, 1, 0);
		else
		{
			bigint_add_digit(decimal, 1, round_idx + 1);
			if (decimal->size != decimal_original_size)
			{
				bigint_add_digit(integer, 1, 0);
				bigint_resize(decimal, decimal->size - 1);
			}
		}
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
	t_bigint		*integer;
	t_bigint		*decimal;
	char			*str;

	str = ieee854_check_reserved_bits(ieee854);
	if (!str)
	{
		integer = ieee854_get_integer_part(ieee854);
		decimal = ieee854_get_decimal_part(ieee854);
		round_number(integer, decimal, precision);
		str = join_integer_decimal(integer, decimal);
		free_bigint(integer);
		free_bigint(decimal);
	}
	return (str);
}
