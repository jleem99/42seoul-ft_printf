/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_to_str.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 03:24:23 by jleem             #+#    #+#             */
/*   Updated: 2021/05/23 17:10:29 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAT_TO_STR_H
# define FLOAT_TO_STR_H

# ifdef __linux__
#  include <bits/endian.h>
# elif defined __APPLE__
#  include <machine/endian.h>
# else
#  include <machine/endian.h>
# endif

typedef unsigned int	t_size;

typedef union	u_ieee754_double
{
	double		d;

	struct
	{
		t_size	mantissa1:32;
		t_size	mantissa0:20;
		t_size	exponent:11;
		t_size	negative:1;
	}			ieee;

	struct
	{
		t_size	mantissa1:32;
		t_size	mantissa0:19;
		t_size	quiet_nan:1;
		t_size	exponent:11;
		t_size	negative:1;
	}			ieee_nan;
}				t_ieee754;

# define IEEE754_DOUBLE_BIAS 0x3ff

typedef union	u_ieee854_long_double
{
	long double	d;

	struct
	{
		t_size	mantissa1:32;
		t_size	mantissa0:32;
		t_size	exponent:15;
		t_size	negative:1;
		t_size	empty:16;
	}			ieee;

	struct
	{
		t_size	mantissa1:32;
		t_size	mantissa0:30;
		t_size	quiet_nan:1;
		t_size	one:1;
		t_size	exponent:15;
		t_size	negative:1;
		t_size	empty:16;
	}			ieee_nan;
}				t_ieee854;

# define IEEE854_LONG_DOUBLE_BIAS 0x3fff

char			*long_double_to_str_10(long double flt, int precision);

#endif
