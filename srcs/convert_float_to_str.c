/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_float_to_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 01:09:46 by jleem             #+#    #+#             */
/*   Updated: 2021/05/31 04:39:48 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include "libft_bonus.h"
#include <stdlib.h>

t_bigint	*ieee854_get_integer_part(t_ieee854 ieee854)
{
	t_bigint *const	integer = make_bigint(1, 10);
	int const		num_bits = ieee854_get_unbiased_exponent(ieee854) + 1;
	int				leftover_bits;

	convert_mantissa_to_bigint(integer,
		ieee854_get_mantissa(ieee854, 0, num_bits));
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
	int				decimalifier;

	if (unused_bits >= 64)
		return (decimal);
	convert_mantissa_to_bigint(decimal,
		ieee854_get_mantissa(ieee854, unused_bits, 64));
	decimalifier = 0;
	while (decimalifier++ < num_bits)
		bigint_multiply(decimal, 5);
	bigint_resize(decimal, num_bits);
	return (decimal);
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

char		*long_double_to_str_10(t_ieee854 ieee854, int precision)
{
	t_bigint	*integer;
	t_bigint	*decimal;
	t_bigint	*number;
	char		*str;

	str = ieee854_check_reserved_bits(ieee854);
	if (!str)
	{
		integer = ieee854_get_integer_part(ieee854);
		decimal = ieee854_get_decimal_part(ieee854);
		number = bigint_append(integer, decimal);
		if (round_number(number, integer->size + precision))
			integer->size++;
		str = bigint_to_string(number);
		add_decimal_point(&str, integer->size);
		free_bigint(integer);
		free_bigint(decimal);
		free_bigint(number);
	}
	return (str);
}

static int	handle_exponent(t_bigint *number, size_t integer_size)
{
	int		exponent;

	exponent = 0;
	while (number->data[number->size - 1] == 0)
	{
		bigint_resize(number, number->size - 1);
		exponent--;
	}
	if (exponent == 0)
		exponent = integer_size - 1;
	return (exponent);
}
#include <stdio.h>
static void	add_exponent_notation(char **pstr, int exponent)
{
	char	*new_str;
	char	exponent_notation[8];
	
	snprintf(exponent_notation, 8, "e%+0.2d", exponent);
	new_str = ft_strjoin(*pstr, exponent_notation);
	free(*pstr);
	*pstr = new_str;
}


static void	add_decimal_point_force(char **pstr, size_t integer_len)
{
	char			*new_str;
	size_t const	slen = ft_strlen(*pstr);
	char *const		integer_str = *pstr;
	char *const		decimal_str = integer_str + integer_len;

	new_str = malloc(ft_strlen(*pstr) + 2);
	ft_memcpy(new_str, integer_str, integer_len);
	new_str[integer_len] = '.';
	ft_strcpy(new_str + integer_len + 1, decimal_str);
	free(*pstr);
	*pstr = new_str;
}

char		*long_double_to_str_10_e(t_ieee854 ieee854, int precision, int apply_pound)
{
	t_bigint	*integer;
	t_bigint	*decimal;
	t_bigint	*number;
	char		*str;
	int			exponent;

	str = ieee854_check_reserved_bits(ieee854);
	if (!str)
	{
		integer = ieee854_get_integer_part(ieee854);
		decimal = ieee854_get_decimal_part(ieee854);
		number = bigint_append(integer, decimal);
		exponent = handle_exponent(number, integer->size);
		if (round_number(number, 1 + precision))
		{
			integer->size++;
			round_number(number, 1 + precision);
		}
		str = bigint_to_string(number);
		if (ft_strlen(str) != 1 || apply_pound)
			add_decimal_point_force(&str, 1);
		add_exponent_notation(&str, exponent); // handle exponent when overflow occurs
		free_bigint(integer);
		free_bigint(decimal);
		free_bigint(number);
	}
	return (str);
}
