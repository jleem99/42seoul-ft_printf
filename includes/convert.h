/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 21:59:07 by jleem             #+#    #+#             */
/*   Updated: 2021/05/31 03:28:12 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H

# include "ieee854.h"

/*
** Convert integer to string
*/
char		*intmax_to_str_10(intmax_t n);
char		*uintmax_to_str_10(uintmax_t n);
char		*uintmax_to_str_8(uintmax_t n);
char		*uintmax_to_str_16(uintmax_t n, char base);

/*
** Convert floating point to string
*/
char		*long_double_to_str_10(long double flt, int precision);

int			ieee854_get_unbiased_exponent(t_ieee854 ieee854);
int			ieee854_is_negative(long double flt);
uint64_t	ieee854_get_mantissa(t_ieee854 ieee854, int start_bit, int end_bit);

#endif
