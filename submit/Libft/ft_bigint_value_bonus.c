/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_value_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 21:56:17 by jleem             #+#    #+#             */
/*   Updated: 2021/05/31 01:38:26 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	bigint_set_value(t_bigint *bigint, uint64_t value)
{
	if (bigint->size < 8)
		bigint_resize(bigint, 8);
	ft_bzero(bigint->data, bigint->size);
	ft_memcpy(bigint->data, &value, 8);
}

/*
** [bigint_set_digit]
** Note: uint8_t carry can overflow when not used internally
*/

void	bigint_set_digit(t_bigint *bigint, uint16_t value, size_t byteidx)
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
		bigint_add_digit(bigint, carry, carry_byteidx);
		bigint->data[byteidx] = remainder;
	}
}

void	bigint_add_digit(t_bigint *bigint, uint8_t addend, size_t byteidx)
{
	uint16_t	sum;

	sum = bigint->data[byteidx] + addend;
	bigint_set_digit(bigint, sum, byteidx);
}

void	bigint_add(t_bigint *bigint, t_bigint *addend)
{
	size_t		byteidx;
	uint16_t	sum;

	if (bigint->size < addend->size)
		bigint_resize(bigint, addend->size);
	byteidx = 0;
	while (byteidx < addend->size)
	{
		sum = bigint->data[byteidx] + addend->data[byteidx];
		bigint_set_digit(bigint, sum, byteidx);
		byteidx++;
	}
}

void	bigint_multiply(t_bigint *bigint, uint8_t multiplier)
{
	size_t		byteidx;
	uint16_t	product;

	byteidx = bigint->size;
	while (byteidx-- > 0)
	{
		product = bigint->data[byteidx] * multiplier;
		bigint_set_digit(bigint, product, byteidx);
	}
}
