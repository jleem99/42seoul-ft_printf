/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_float_to_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 01:09:46 by jleem             #+#    #+#             */
/*   Updated: 2021/05/31 11:52:46 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include "specifier.h"
#include "libft_bonus.h"
#include <stdlib.h>

t_bigint	*ieee854_get_integer_part(t_ieee854 ieee854)
{
	t_bigint *const	integer = make_bigint(1, 10);
	int const		num_bits = ieee854_get_unbiased_exponent(ieee854) + 1;
	uint64_t const	mantissa = ieee854_get_mantissa(ieee854, 0, num_bits);
	int				leftover_bits;

	if (mantissa == 0)
		return (integer);
	convert_mantissa_to_bigint(integer, mantissa);
	leftover_bits = num_bits - 64;
	while (leftover_bits-- > 0)
		bigint_multiply(integer, 2);
	return (integer);
}

t_bigint	*ieee854_get_decimal_part(t_ieee854 ieee854)
{
	t_bigint *const	decimal = make_bigint(0, 10);
	int const		unused_bits = ieee854_get_unbiased_exponent(ieee854) + 1;
	int const		num_bits = 64 - unused_bits;
	uint64_t const	mantissa = ieee854_get_mantissa(ieee854, unused_bits, 64);
	int				decimalifier;

	if (mantissa == 0)
		return (decimal);
	convert_mantissa_to_bigint(decimal, mantissa);
	decimalifier = 0;
	while (decimalifier++ < num_bits)
		bigint_multiply(decimal, 5);
	bigint_resize(decimal, num_bits);
	return (decimal);
}

char		*long_double_to_str_10(t_ieee854 ieee854, t_specifier *specifier)
{
	t_bigint	*integer;
	t_bigint	*decimal;
	t_bigint	*number;
	char		*str;
	int			precision;

	if (specifier->precision == -1)
		precision = 6;
	else
		precision = specifier->precision;
	str = ieee854_check_reserved_bits(ieee854);
	if (!str)
	{
		integer = ieee854_get_integer_part(ieee854);
		decimal = ieee854_get_decimal_part(ieee854);
		number = bigint_append(integer, decimal);
		if (round_number(number, integer->size + precision))
			integer->size++;
		str = bigint_to_string(number);
		add_decimal_point(&str, integer->size, specifier->f_pound);
		free_bigint(integer);
		free_bigint(decimal);
		free_bigint(number);
	}
	return (str);
}
