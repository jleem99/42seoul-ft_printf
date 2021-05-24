/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 05:09:36 by jleem             #+#    #+#             */
/*   Updated: 2021/05/25 05:09:43 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"
#include "libft.h"

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
