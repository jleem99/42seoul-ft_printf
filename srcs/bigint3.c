/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 05:09:36 by jleem             #+#    #+#             */
/*   Updated: 2021/05/25 18:33:48 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"
#include "libft.h"
#include <stdlib.h>

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

char		*bigint_to_string(t_bigint *bigint)
{
	char *const	string = malloc(bigint->size + 1);
	size_t		byteidx;

	byteidx = 0;
	while (byteidx < bigint->size)
	{
		string[bigint->size - 1 - byteidx] = '0' + bigint->data[byteidx];
		byteidx++;
	}
	string[byteidx] = '\0';
	return (string);
}

char		*bigint_to_string_hex(t_bigint *bigint, char base)
{
	char *const	string = malloc(bigint->size + 1);
	uint8_t		byte;
	size_t		byteidx;

	byteidx = 0;
	while (byteidx < bigint->size)
	{
		byte = bigint->data[byteidx];
		if (byte < 10)
			string[bigint->size - 1 - byteidx] = '0' + byte;
		else
			string[bigint->size - 1 - byteidx] = base + (byte - 10);
		byteidx++;
	}
	string[byteidx] = '\0';
	return (string);
}
