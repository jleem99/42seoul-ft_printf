/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_float_to_str_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 04:00:51 by jleem             #+#    #+#             */
/*   Updated: 2021/05/30 04:13:12 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"

int			ieee854_get_unbiased_exponent(t_ieee854 ieee854)
{
	return (ieee854.bitfield.exponent - IEEE854_LONG_DOUBLE_BIAS);
}

int			ieee854_is_negative(long double flt)
{
	t_ieee854 const	ieee854 = { flt };

	return (ieee854.bitfield.negative);
}

/*
** Get mantissa bits: [start_bit, end_bit)
*/
// Ensure very first bit of mantissa to be zero
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
