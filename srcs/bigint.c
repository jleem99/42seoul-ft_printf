/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:27:30 by jleem             #+#    #+#             */
/*   Updated: 2021/05/25 17:06:33 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"
#include "libft.h"
#include <stdlib.h>

t_bigint	*make_bigint(size_t size)
{
	t_bigint *const	bigint = malloc(sizeof(t_bigint));

	bigint->data = ft_calloc(size, sizeof(uint8_t));
	bigint->base = 10;
	bigint->size = size;
	return (bigint);
}

void		free_bigint(t_bigint *bigint)
{
	free(bigint->data);
	free(bigint);
}

void		bigint_resize(t_bigint *bigint, size_t new_size)
{
	uint8_t *const	new_data = ft_calloc(new_size, sizeof(uint8_t));

	if (new_size > bigint->size)
		ft_memcpy(new_data, bigint->data, bigint->size);
	else
		ft_memcpy(new_data, bigint->data, new_size);
	free(bigint->data);
	bigint->data = new_data;
	bigint->size = new_size;
}

void		bigint_set_value(t_bigint *bigint, uint64_t value)
{
	if (bigint->size < 8)
		bigint_resize(bigint, 8);
	ft_bzero(bigint->data, bigint->size);
	ft_memcpy(bigint->data, &value, 8);
}

/*
** Note: uint8_t carry can overflow when not used internally
*/

void		bigint_set_digit(t_bigint *bigint, uint16_t value, size_t byteidx)
{
	size_t const	carry_byteidx = byteidx + 1;
	uint8_t			carry;
	uint8_t			remainder;

	if (byteidx >= bigint->size)
		bigint_resize(bigint, byteidx + 1);
	if (value < bigint->base)
	{
		bigint->data[byteidx] = value;
	}
	else
	{
		if (carry_byteidx == bigint->size)
			bigint_resize(bigint, bigint->size + 1);
		carry = value / bigint->base;
		remainder = value % bigint->base;
		bigint_add_with_index(bigint, carry, carry_byteidx);
		bigint->data[byteidx] = remainder;
	}
}
