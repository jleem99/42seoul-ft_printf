/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_to_str.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 03:24:23 by jleem             #+#    #+#             */
/*   Updated: 2021/05/23 03:47:09 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAT_TO_STR_H
# define FLOAT_TO_STR_H

# include <ieee754.h>

typedef union ieee754_double		t_ieee754;
typedef union ieee854_long_double	t_ieee854;

char	*long_double_to_str_10(long double flt, int precision);

#endif
