/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 22:32:06 by jleem             #+#    #+#             */
/*   Updated: 2021/05/31 01:31:31 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"
#include <stdlib.h>

t_bigint	*bigint_copy(t_bigint *bigint)
{
	t_bigint *const	new_bigint = make_bigint(bigint->size, bigint->base);

	ft_memcpy(new_bigint->data, bigint->data, bigint->size);
	return (new_bigint);
}

uint8_t		*bigint_copy_data(t_bigint *bigint)
{
	uint8_t *const	new_data = malloc(bigint->size);

	ft_memcpy(new_data, bigint->data, bigint->size);
	return (new_data);
}

t_bigint	*bigint_append(t_bigint *bigint1, t_bigint *bigint2)
{
	t_bigint	*new_bigint;

	new_bigint = make_bigint(bigint1->size + bigint2->size, bigint1->base);
	ft_memcpy(new_bigint->data, bigint2->data, bigint2->size);
	ft_memcpy(new_bigint->data + bigint2->size, bigint1->data, bigint1->size);
	return (new_bigint);
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

void		bigint_resize_reverse(t_bigint *bigint, size_t new_size)
{
	uint8_t *const	new_data = ft_calloc(new_size, sizeof(uint8_t));
	int const		delta_size = new_size - bigint->size;

	if (new_size > bigint->size)
		ft_memcpy(new_data + delta_size, bigint->data, bigint->size);
	else
		ft_memcpy(new_data, bigint->data - delta_size, new_size);
	free(bigint->data);
	bigint->data = new_data;
	bigint->size = new_size;
}
