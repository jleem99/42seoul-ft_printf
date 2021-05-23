/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:27:30 by jleem             #+#    #+#             */
/*   Updated: 2021/05/23 21:40:42 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"
#include "libft.h"
#include <stdlib.h>

t_bigint	*make_bigint(t_size size)
{
	t_bigint *const	bigint = malloc(sizeof(t_bigint));

	bigint->data = ft_calloc(size, sizeof(char));
	bigint->size = size;
	return (bigint);
}

void		free_bigint(t_bigint *bigint)
{
	free(bigint->data);
	free(bigint);
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

void		bigint_shift(t_bigint *bigint, t_size bits)
{
	t_size const	bytes_to_push = bits / 8;
	t_size const	bits_to_push = bits - 8 * bytes_to_push;

	bigint_shift_bytes(bigint, bytes_to_push);
	bigint_shift_bits_internal(bigint, bits_to_push);
}

void		bigint_inspect_byte(t_bigint *bigint, t_size byteidx)
{
	int		bitmask;
	int		bit;

	bitmask = 0b10000000;
	while (bitmask != 0)
	{
		bit = (bigint->data[byteidx] & bitmask) != 0;
		ft_putchar_fd(bit + '0', 1);
		bitmask >>= 1;
	}
}

void		bigint_inspect(t_bigint *bigint)
{
	t_size	i;

	i = 0;
	while (i < bigint->size)
	{
		if (i % 4 == 0)
			ft_putchar_fd('\n', 1);
		else
			ft_putchar_fd(' ', 1);
		bigint_inspect_byte(bigint, (bigint->size - 1 - i));
		i++;
	}
}
