/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_float_to_str_e.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:20:50 by jleem             #+#    #+#             */
/*   Updated: 2021/07/08 17:51:45 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include "specifier.h"
#include "ft_printf.h"
#include "libft_bonus.h"
#include <stdlib.h>

static int	handle_exponent(t_bigint *number, size_t integer_size)
{
	int		exponent;

	if (number->size == 1 && number->data[0] == 0)
		return (0);
	exponent = 0;
	while (number->data[number->size - 1 + exponent] == 0)
		exponent--;
	if (exponent != 0)
		bigint_resize(number, number->size + exponent);
	else
		exponent = integer_size - 1;
	return (exponent);
}

static void	add_exponent_notation(char **pstr, int exponent)
{
	char	*new_str;
	char	exponent_notation[8];

	ft_sprintf(exponent_notation, "e%+0.2d", exponent);
	new_str = ft_strjoin(*pstr, exponent_notation);
	free(*pstr);
	*pstr = new_str;
}

char	*format_str_e(t_bigint *number, t_bigint *integer,
							t_specifier *specifier)
{
	char		*str;
	int			exponent;
	int			precision;

	if (specifier->precision == -1)
		precision = 6;
	else
		precision = specifier->precision;
	exponent = handle_exponent(number, integer->size);
	if (round_number(number, 1 + precision))
	{
		exponent++;
		round_number(number, 1 + precision);
	}
	str = bigint_to_string(number);
	add_decimal_point(&str, 1, specifier->f_pound);
	add_exponent_notation(&str, exponent);
	return (str);
}
