/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_to_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 01:09:46 by jleem             #+#    #+#             */
/*   Updated: 2021/05/23 23:01:55 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float_to_str.h"
#include "bigint.h"

t_size			get_unbiased_exponent(t_ieee854 ieee854)
{
	return (ieee854.ieee.exponent - IEEE854_LONG_DOUBLE_BIAS);
}


t_bigint		*long_double_extract_integer(t_ieee854 ieee854)
{
	t_size const	exponent = get_unbiased_exponent(ieee854);
	t_bigint		*integer;
	t_size			buf;

	if ((exponent + 1) % 8 == 0)
	{
		integer = make_bigint((exponent + 1) / 8);
		buf = ieee854.ieee.mantissa0;
		ft_memcpy(integer->data, &buf, (exponent + 1) / 8);
	}
	else
	{
		integer = make_bigint((exponent + 1) / 8 + 1);
		
	}
	return (integer);
}

#include <stdio.h>
#include "libft.h"
char			*long_double_to_str_10(long double flt, int precision)
{
	t_ieee854 const	ieee854 = { flt };
	t_bigint		*decimal;





	// 8.5
	// 1000.1
	// 1.0001 * 2^2
	// 11011001001101001.00100100010010001
}

char			*long_double_to_str_16(long double flt, int precision)
{
	
}
