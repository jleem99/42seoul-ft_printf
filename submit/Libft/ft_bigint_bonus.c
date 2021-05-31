/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigint_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:27:30 by jleem             #+#    #+#             */
/*   Updated: 2021/05/26 22:44:20 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"
#include <stdlib.h>

t_bigint	*make_bigint(size_t size, uint8_t base)
{
	t_bigint *const	bigint = malloc(sizeof(t_bigint));

	bigint->data = ft_calloc(size, sizeof(uint8_t));
	bigint->base = base;
	bigint->size = size;
	return (bigint);
}

void		free_bigint(t_bigint *bigint)
{
	free(bigint->data);
	free(bigint);
}
