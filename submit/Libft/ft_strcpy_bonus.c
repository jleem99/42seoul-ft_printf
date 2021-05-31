/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:15:40 by jleem             #+#    #+#             */
/*   Updated: 2021/05/26 22:39:57 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

char	*ft_strcpy(char *dest, char *src)
{
	char *const	ret = dest;

	while (*src != '\0')
		*(dest++) = *(src++);
	*dest = '\0';
	return (ret);
}
