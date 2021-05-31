/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_pop_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 13:31:08 by jleem             #+#    #+#             */
/*   Updated: 2021/02/04 01:22:22 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	*ft_array_pop(t_array *arr)
{
	void	**data_new;
	void	*ret;
	size_t	i;

	if (!(data_new = malloc(sizeof(void *) * (arr->size - 1))))
		return (NULL);
	i = 0;
	while (i < arr->size - 1)
	{
		data_new[i] = arr->data[i];
		i++;
	}
	ret = arr->data[i];
	free(arr->data);
	arr->data = data_new;
	arr->size--;
	return (ret);
}
