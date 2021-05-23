/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 17:27:30 by jleem             #+#    #+#             */
/*   Updated: 2021/05/23 22:00:51 by jleem            ###   ########.fr       */
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
