/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_push_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 13:21:05 by jleem             #+#    #+#             */
/*   Updated: 2021/02/04 01:22:33 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

int		ft_array_push(t_array *arr, void *element)
{
	void	**data_new;
	size_t	i;

	if (!(data_new = malloc(sizeof(void *) * (arr->size + 1))))
		return (0);
	i = 0;
	while (i < arr->size)
	{
		data_new[i] = arr->data[i];
		i++;
	}
	data_new[i] = element;
	free(arr->data);
	arr->data = data_new;
	arr->size++;
	return (1);
}
