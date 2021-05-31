/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 00:09:07 by jleem             #+#    #+#             */
/*   Updated: 2021/01/12 00:40:37 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(void const *b1, void const *b2, size_t n)
{
	size_t	i;

	if (b1 == b2 || n == 0)
		return (0);
	i = 0;
	while (i < n - 1 && ((unsigned char *)b1)[i] == ((unsigned char *)b2)[i])
		i++;
	return (((unsigned char *)b1)[i] - ((unsigned char *)b2)[i]);
}
