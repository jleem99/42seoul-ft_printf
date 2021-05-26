/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 21:56:17 by jleem             #+#    #+#             */
/*   Updated: 2021/05/26 21:05:25 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"

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
	while (byteidx > 0)
	{
		byteidx--;
		product = bigint->data[byteidx] * multiplier;
		bigint_set_digit(bigint, product, byteidx);
	}
}
