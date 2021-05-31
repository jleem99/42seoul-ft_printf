/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_array_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 13:16:26 by jleem             #+#    #+#             */
/*   Updated: 2021/02/14 15:44:25 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

t_array	*ft_make_array(size_t size)
{
	t_array	*ret;

	if (!(ret = malloc(sizeof(t_array))))
		return (NULL);
	if (!(ret->data = malloc(sizeof(void *) * size)) && size != 0)
	{
		free(ret);
		return (NULL);
	}
	ret->size = size;
	return (ret);
}
