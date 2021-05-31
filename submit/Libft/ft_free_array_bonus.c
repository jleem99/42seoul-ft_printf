/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 13:20:24 by jleem             #+#    #+#             */
/*   Updated: 2021/02/14 15:21:34 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	ft_free_array(t_array *arr)
{
	free(arr->data);
	free(arr);
}

void	ft_free_array_data(t_array *arr)
{
	size_t	i;

	i = 0;
	while (i < arr->size)
		free(arr->data[i++]);
}

void	ft_free_array_all(t_array *arr)
{
	ft_free_array_data(arr);
	ft_free_array(arr);
}
