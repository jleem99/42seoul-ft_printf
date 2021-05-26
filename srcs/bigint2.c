/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 22:32:06 by jleem             #+#    #+#             */
/*   Updated: 2021/05/26 22:32:08 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bigint.h"
#include "libft.h"
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
