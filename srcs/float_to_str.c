/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_to_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 01:09:46 by jleem             #+#    #+#             */
/*   Updated: 2021/05/23 14:38:01 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float_to_str.h"

unsigned int	get_unbiased_exponent(t_ieee854 ieee854)
{
	return (ieee854.ieee.exponent - IEEE854_LONG_DOUBLE_BIAS);
}

char			get_nth_digit(t_ieee854 ieee854)
{
	char	digit;

	// while (!is_digit_accurate())
	// {
		
	// }


}

typedef struct s_bigint t_bigint;


char	*long_double_to_str_10(long double flt, int precision)
{
	t_ieee854		ieee854;
	unsigned int	exponent;
	int				sig;
	// t_bigint		integer_part;
	// t_bigint		decimal_part;

	// integer_part 39

	ieee854.d = flt;
	
	int num = flt;

	8.5
	1000.1
	1.0001 * 2^2
	1101100100110100100100100010010001

	exponent = get_unbiased_exponent(ieee854);
	ieee854.ieee.mantissa0;
	ieee854.ieee.mantissa1;
	ieee854.ieee.negative;
	
}

char	*long_double_to_str_16(long double flt, int precision)
{
	
}
