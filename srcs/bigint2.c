/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 21:56:17 by jleem             #+#    #+#             */
/*   Updated: 2021/05/25 03:45:37 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"
#include "libft.h"

void		bigint_add_with_index(t_bigint *bigint, uint8_t addend, size_t byteidx)
{	
	bigint_set_digit(bigint, bigint->data[byteidx] + addend, byteidx);
}

void		bigint_multiply(t_bigint *bigint, uint8_t multiplier)
{
	ssize_t		byteidx;
	uint16_t	product;

	byteidx = bigint->size - 1;
	while (byteidx >= 0)
	{
		product = bigint->data[byteidx] * multiplier;
		bigint_set_digit(bigint, product, byteidx);
		byteidx--;
	}
}

void		bigint_shift_bytes(t_bigint *bigint, int bytes)
{
	int		i;

	i = bigint->size - 1;
	while (i >= 0)
	{
		if (i - bytes < 0)
			bigint->data[i] = 0;
		else
			bigint->data[i] = bigint->data[i - bytes];
		i--;
	}
}

static void	bigint_shift_bits_internal(t_bigint *bigint, int bits)
{
	int		i;

	i = bigint->size - 1;
	while (i >= 0)
	{
		bigint->data[i] <<= bits;
		if (i - 1 >= 0)
			bigint->data[i] |= (bigint->data[i - 1] >> (8 - bits));
		i--;
	}
}

void		bigint_shift(t_bigint *bigint, size_t bits)
{
	size_t const	bytes_to_push = bits / 8;
	size_t const	bits_to_push = bits % 8;

	bigint_shift_bytes(bigint, bytes_to_push);
	bigint_shift_bits_internal(bigint, bits_to_push);
}
