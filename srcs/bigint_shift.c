/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint_shift.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 22:24:09 by jleem             #+#    #+#             */
/*   Updated: 2021/05/26 22:25:12 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"
#include <stdlib.h>

void		bigint_shift_bytes(t_bigint *bigint, int bytes)
{
	uint8_t *const	new_data = bigint_copy_data(bigint);
	size_t			destidx;
	size_t			srcidx;
	
	destidx = 0;
	while (destidx < bigint->size)
	{
		srcidx = destidx - bytes;
		if ((bytes > 0 && destidx < (size_t)bytes) || srcidx >= bigint->size)
			new_data[destidx] = 0;
		else
			new_data[destidx] = bigint->data[srcidx];
		destidx++;
	}
	free(bigint->data);
	bigint->data = new_data;
}

static void	bigint_shift_bits_internal(t_bigint *bigint, int bits)
{
	uint8_t *const	new_data = bigint_copy_data(bigint);
	size_t			destidx;
	size_t			srcidx;

	destidx = 0;
	while (destidx < bigint->size)
	{
		if (bits > 0)
		{
			srcidx = destidx - 1;
			new_data[destidx] <<= bits;
			if (destidx >= 1)
				new_data[destidx] |= (bigint->data[srcidx] >> (8 - bits));
		}
		else if (bits < 0)
		{
			srcidx = destidx + 1;
			new_data[destidx] >>= (-bits);
			if (srcidx < bigint->size)
				new_data[destidx] |= (bigint->data[srcidx] << (8 - (-bits)));
		}
		destidx++;
	}
	free(bigint->data);
	bigint->data = new_data;
}

void		bigint_shift_bits(t_bigint *bigint, int bits)
{
	int const	bytes_to_push = bits / 8;
	int const	bits_to_push = bits % 8;

	bigint_shift_bytes(bigint, bytes_to_push);
	bigint_shift_bits_internal(bigint, bits_to_push);
}
