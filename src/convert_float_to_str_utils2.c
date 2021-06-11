/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_float_to_str_utils2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 03:20:26 by jleem             #+#    #+#             */
/*   Updated: 2021/05/31 11:51:14 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.h"
#include "libft_bonus.h"

static int	check_smaller_decimal_places(t_bigint *decimal, size_t round_idx)
{
	size_t	byteidx;

	byteidx = round_idx;
	while (byteidx-- > 0)
		if (decimal->data[byteidx] != 0)
			return (1);
	return (0);
}

static int	check_round_condition(t_bigint *number, int precision)
{
	size_t const	round_idx = number->size - (precision + 1);

	if (number->size > (size_t)(precision + 1))
	{
		if (number->data[round_idx] > 5)
			return (1);
		else if (number->data[round_idx] == 5)
		{
			if (check_smaller_decimal_places(number, round_idx))
				return (1);
			else
				return (number->data[round_idx + 1] % 2 == 1);
		}
	}
	return (0);
}

int			round_number(t_bigint *number, int precision)
{
	size_t const	round_idx = number->size - (precision + 1);
	size_t const	original_size = number->size;
	int				overflow;

	if (check_round_condition(number, precision))
		bigint_add_digit(number, 1, round_idx + 1);
	overflow = (number->size != original_size);
	if (overflow)
		bigint_resize_reverse(number, precision + 1);
	else
		bigint_resize_reverse(number, precision);
	return (overflow);
}

void		add_decimal_point(char **pstr, size_t integer_len, int f_pound)
{
	char			*new_str;
	size_t const	slen = ft_strlen(*pstr);
	char *const		integer_str = *pstr;
	char *const		decimal_str = integer_str + integer_len;

	if (integer_len == slen && !f_pound)
		return ;
	new_str = malloc(ft_strlen(*pstr) + 2);
	ft_memcpy(new_str, integer_str, integer_len);
	new_str[integer_len] = '.';
	ft_strcpy(new_str + integer_len + 1, decimal_str);
	free(*pstr);
	*pstr = new_str;
}
