/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 00:09:10 by jleem             #+#    #+#             */
/*   Updated: 2021/01/12 00:40:37 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void const *src, size_t n)
{
	size_t	i;

	if (dest == src || n == 0)
		return (dest);
	if (dest > src && dest - src < (int)n)
	{
		i = n;
		while (--i != (size_t)-1)
			((char *)dest)[i] = ((char *)src)[i];
	}
	else if (src > dest && src - dest < (int)n)
	{
		i = -1;
		while (++i < n)
			((char *)dest)[i] = ((char *)src)[i];
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}
