/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jleem <jleem@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 20:20:55 by jleem             #+#    #+#             */
/*   Updated: 2021/05/26 22:39:51 by jleem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

char	*ft_strcat(char *dest, char *src)
{
	char *const	ret = dest;

	while (*dest != '\0')
		dest++;
	while (*src != '\0')
		*(dest++) = *(src++);
	*dest = '\0';
	return (ret);
}
