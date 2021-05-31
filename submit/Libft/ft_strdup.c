/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 00:13:16 by jleem             #+#    #+#             */
/*   Updated: 2021/02/04 01:29:16 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *str)
{
	size_t const	size = ft_strlen(str) + 1;
	char *const		copy = malloc(size);

	if (!copy)
		return (NULL);
	ft_memcpy(copy, str, size);
	return (copy);
}
