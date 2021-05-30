/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_float_to_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 01:09:46 by jleem             #+#    #+#             */
/*   Updated: 2021/05/31 03:16:10 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include "libft_bonus.h"
#include <stdlib.h>

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
	while (byteidx-- > 0)
		if (decimal->data[byteidx] != 0)
			return (1);
	return (0);
}

static int	check_round_condition(t_bigint *number, int precision)
{
	size_t const	round_idx = number->size - (precision + 1);

	if (number->size > (size_t)(precision + 1))
	{
		if (number->data[round_idx] > 5)
			return (1);
		else if (number->data[round_idx] == 5)
		{
			if (check_smaller_decimal_places(number, round_idx))
				return (1);
			else
				return (number->data[round_idx + 1] % 2 == 1);
		}
	}
	return (0);
}

static int	round_number(t_bigint *number, int precision)
{
	size_t const	round_idx = number->size - (precision + 1);
	size_t const	original_size = number->size;
	int				overflow;

	if (check_round_condition(number, precision))
		bigint_add_digit(number, 1, round_idx + 1);
	overflow = (number->size != original_size);
	if (overflow)
		bigint_resize_reverse(number, precision + 1);
	else
		bigint_resize_reverse(number, precision);
	return (overflow);
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

static void	add_decimal_point(char **pstr, size_t integer_len)
{
	char			*new_str;
	size_t const	slen = ft_strlen(*pstr);
	char *const		integer_str = *pstr;
	char *const		decimal_str = integer_str + integer_len;

	if (integer_len == slen)
		return ;
	new_str = malloc(ft_strlen(*pstr) + 2);
	ft_memcpy(new_str, integer_str, integer_len);
	new_str[integer_len] = '.';
	ft_strcpy(new_str + integer_len + 1, decimal_str);
	free(*pstr);
	*pstr = new_str;
}

char		*long_double_to_str_10(long double flt, int precision)
{
	t_ieee854 const	ieee854 = { flt };
	t_bigint		*integer;
	t_bigint		*decimal;
	t_bigint		*number;
	char			*str;

	str = ieee854_check_reserved_bits(ieee854);
	if (!str)
	{
		integer = ieee854_get_integer_part(ieee854);
		decimal = ieee854_get_decimal_part(ieee854);
		number = bigint_append(integer, decimal);
		if (round_number(number, integer->size + precision))
		{
			str = bigint_to_string(number);
			add_decimal_point(&str, integer->size + 1);
		}
		else
		{
			str = bigint_to_string(number);
			add_decimal_point(&str, integer->size);
		}
		free_bigint(integer);
		free_bigint(decimal);
		free_bigint(number);
	}
	return (str);
}
