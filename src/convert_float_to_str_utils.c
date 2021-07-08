/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_float_to_str_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 04:00:51 by jleem             #+#    #+#             */
/*   Updated: 2021/07/08 17:52:03 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include "libft_bonus.h"

int	ieee854_get_unbiased_exponent(t_ieee854 ieee854)
{
	return (ieee854.bitfield.exponent - IEEE854_LONG_DOUBLE_BIAS);
}

int	ieee854_is_negative(t_ieee854 ieee854)
{
	return (ieee854.bitfield.negative);
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

void	convert_mantissa_to_bigint(t_bigint *bigint, uint64_t mantissa)
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

char	*ieee854_check_reserved_bits(t_ieee854 ieee854)
{
	if (ieee854.bitfield.exponent == 32767)
	{
		if (ieee854.reserved.section0 == 0b00
			|| ieee854.reserved.section0 == 0b01
			|| ieee854.reserved.section0 == 0b11)
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
