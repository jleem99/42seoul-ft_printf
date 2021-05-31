/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ieee854.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 03:24:11 by jleem             #+#    #+#             */
/*   Updated: 2021/05/31 03:24:56 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IEEE854_H
# define IEEE854_H

# ifdef __linux__
#  include <bits/endian.h>
# elif defined __APPLE__
#  include <machine/endian.h>
# else
#  include <machine/endian.h>
# endif

# include <stdint.h>

typedef union		u_ieee754_double
{
	double			d;

	struct
	{
		uint32_t	mantissa1	: 32;
		uint32_t	mantissa0	: 20;
		uint32_t	exponent	: 11;
		uint32_t	negative	: 1;
	}				bitfield;

	struct
	{
		uint32_t	mantissa1	: 32;
		uint32_t	mantissa0	: 19;
		uint32_t	quiet_nan	: 1;
		uint32_t	exponent	: 11;
		uint32_t	negative	: 1;
	}				ieee_nan;
}					t_ieee754;

# define IEEE754_DOUBLE_BIAS 0x3ff

typedef union		u_ieee854_long_double
{
	long double		d;

	struct
	{
		uint32_t	mantissa1	: 32;
		uint32_t	mantissa0	: 32;
		uint32_t	exponent	: 15;
		uint32_t	negative	: 1;
		uint32_t	empty		: 16;
	}				bitfield;

	struct
	{
		uint64_t	section1	: 62;
		uint32_t	section0	: 2;
		uint32_t	exponent	: 15;
		uint32_t	negative	: 1;
		uint32_t	empty		: 16;
	}				reserved;
}					t_ieee854;

# define IEEE854_LONG_DOUBLE_BIAS 0x3fff

#endif
